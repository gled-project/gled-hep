// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef XrdMon_XrdEhs_H
#define XrdMon_XrdEhs_H

#include <Glasses/ZNameMap.h>
#include <Gled/GTime.h>

#include "TPRegexp.h"

namespace gled {

class XrdMonSucker;
class XrdFile;

class SSocket;


class XrdEhs : public ZNameMap
{
private:
  void _init();

  Bool_t	       b_stop_server; //!

  GMutex               m_re_mutex;    //!
  TPMERegexp           m_req_line_re; //!
  TPMERegexp           m_req_re;      //!

protected:
  ZLink<XrdMonSucker>  mXrdSucker;    // X{GS} L{a}
  Int_t	               mPort;         // X{GS} 7 Value(-range=>[1,65535,1])
  Float_t              mSelectTOut;   // X{GS} 7 Value(-range=>[1, 60, 1, 100])
  Bool_t	       bServerUp;     // X{GS} 7 BoolOut()

  Bool_t               bParanoia;     // X{GS} 7 Bool()
  TString              mWebTableJs;   // X{GS} 7 Textor()
  Int_t                mRefresh;      // X{GS} 7 Value(-range=>[5,86400,1])

  std::list<XrdFile*>       mFileList;     //!
  TimeStamp_t          mFileListTS;   //!
  GMutex               mServeMutex;   //!

  void release_file_list();
  void update_file_list();

  void fill_content(const GTime& req_time, TString& content, lStr_t& path, mStr2Str_t& args);

public:
  XrdEhs(const Text_t* n="XrdEhs", const Text_t* t=0);
  virtual ~XrdEhs();

  void StartServer(); // X{Ed} 7 MButt(-join=>1)
  void StopServer();  // X{E}  7 MButt()

  void ServePage(SSocket* sock);

#include "XrdEhs.h7"
  ClassDef(XrdEhs, 1);
}; // endclass XrdEhs

} // endnamespace gled

#endif
