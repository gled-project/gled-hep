// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef XrdMon_SXrdServerInfo_H
#define XrdMon_SXrdServerInfo_H

#include "Rtypes.h"
#include "TString.h"

namespace gled {

#ifndef __CINT__
class XrdServer;
#endif

class SXrdServerInfo
{
public:
  TString           mHost;
  TString           mDomain;
  TString           mSite;

  SXrdServerInfo()  {}
  ~SXrdServerInfo() {}

#ifndef __CINT__
  void Assign(const XrdServer* s);
#endif

  ClassDefNV(SXrdServerInfo, 2);
}; // endclass SXrdServerInfo

} // endnamespace gled

#endif
