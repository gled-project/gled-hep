// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef XrdMon_XrdFileCloseReporter_H
#define XrdMon_XrdFileCloseReporter_H

#include "Glasses/ZGlass.h"
#include "Gled/GCondition.h"

namespace gled {

class XrdFile;
class XrdUser;
class XrdServer;
class ZLog;

class GThread;


class XrdFileCloseReporter : public ZGlass
{
  MAC_RNR_FRIENDS(XrdFileCloseReporter);

public:
  struct FileUserServer
  {
    XrdFile   *fFile;
    XrdUser   *fUser;
    XrdServer *fServer;

    FileUserServer() :
      fFile(0), fUser(0), fServer (0) {}
    FileUserServer(XrdFile* f, XrdUser* u, XrdServer* s) :
      fFile(f), fUser(u), fServer (s) {}
  };

private:
  void _init();

protected:
  ZLink<ZLog>           mLog;             // X{GS} L{}

  Int_t                 mCondWaitSec;     // X{GS} 7 Value(-range=>[0, 10000, 1])

  Bool_t                bFixedUuid;       //  X{G} 7 BoolOut()
  TString               mUuid;            //  X{G} 7 TextOut()

  ULong64_t             mNProcessedTotal; //! X{G} 7 ValOut()
  ULong64_t             mNProcessed;      //! X{G} 7 ValOut()
  UInt_t                mNQueued;         //! X{G} 7 ValOut(-join=>1)
  Bool_t                bRunning;         //! X{G} 7 BoolOut()

  GThread              *mReporterThread;  //!
  GCondition            mReporterCond;    //!
  std::list<FileUserServer>  mReporterQueue;   //!

  static void* tl_ReportLoop(XrdFileCloseReporter* r);
  static void  cu_ReportLoop(XrdFileCloseReporter* r);
  void ReportLoop();
  void DrainQueue();

  virtual void ReportLoopInit();
  virtual void ReportFileClosed(FileUserServer& fus);
  virtual void ReportCondWaitTimeout();
  virtual void ReportLoopFinalize();

public:
  XrdFileCloseReporter(const Text_t* n="XrdFileCloseReporter", const Text_t* t=0);
  virtual ~XrdFileCloseReporter();

  void FixUuidString(const TString& uuid); // X{E} 7 MCWButt(-join=>1)
  void AutomaticUuidString();              // X{E} 7 MButt()

  void FileClosed(XrdFile* file, XrdUser* user, XrdServer* server);

  void StartReporter(); // X{Ed} 7 MButt(-join=>1)
  void StopReporter();  // X{Ed} 7 MButt()

#include "XrdFileCloseReporter.h7"
  ClassDef(XrdFileCloseReporter, 1);
}; // endclass XrdFileCloseReporter

} // endnamespace gled

#endif
