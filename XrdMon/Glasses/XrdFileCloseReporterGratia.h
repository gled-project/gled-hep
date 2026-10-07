// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef XrdMon_XrdFileCloseReporterGratia_H
#define XrdMon_XrdFileCloseReporterGratia_H

#include <Glasses/XrdFileCloseReporter.h>

struct sockaddr;

namespace gled {

class XrdFileCloseReporterGratia : public XrdFileCloseReporter
{
  MAC_RNR_FRIENDS(XrdFileCloseReporterGratia);

private:
  void _init();

protected:
  TString           mUdpHost; // X{GS} 7 Textor()
  UShort_t          mUdpPort; // X{GS} 7 Value()

  Bool_t            bDomenicoIds;    //! X{GS} 7 Bool()

  Int_t             mReporterSocket; //!

  Long64_t          mLastUidBase;    //!
  Long64_t          mLastUidInner;   //!

  struct sockaddr  *mSAddr;          //!

  virtual void ReportLoopInit();
  virtual void ReportFileClosed(FileUserServer& fus);
  virtual void ReportLoopFinalize();

public:
  XrdFileCloseReporterGratia(const Text_t* n="XrdFileCloseReporterGratia", const Text_t* t=0);
  virtual ~XrdFileCloseReporterGratia();

#include "XrdFileCloseReporterGratia.h7"
  ClassDef(XrdFileCloseReporterGratia, 1);
}; // endclass XrdFileCloseReporterGratia

} // endnamespace gled

#endif
