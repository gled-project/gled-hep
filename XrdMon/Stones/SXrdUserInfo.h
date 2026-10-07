// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef XrdMon_SXrdUserInfo_H
#define XrdMon_SXrdUserInfo_H

#include "Rtypes.h"
#include "TString.h"

namespace gled {

#ifndef __CINT__
class XrdUser;
#endif

class SXrdUserInfo
{
public:
  TString           mName;

  TString           mRealName;
  TString           mDN;
  TString           mVO;
  TString           mRole;
  TString           mGroup;
  TString           mServerUsername;
  TString           mFromHost;
  TString           mFromDomain;
  TString           mProtocol;
  TString           mAppInfo;
  Long64_t          mLoginTime;
  Bool_t            bNumericHost;

  SXrdUserInfo()  {}
  ~SXrdUserInfo() {}

#ifndef __CINT__
  void Assign(const XrdUser* s);
#endif

  ClassDefNV(SXrdUserInfo, 2);
}; // endclass SXrdUserInfo

} // endnamespace gled

#endif
