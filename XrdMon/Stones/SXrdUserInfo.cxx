// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "SXrdUserInfo.h"
#include "Glasses/XrdUser.h"

using namespace gled;

// SXrdUserInfo

//______________________________________________________________________________
//
//

//==============================================================================

void SXrdUserInfo::Assign(const XrdUser* s)
{
  mName = s->RefName();

  mRealName = s->RefRealName();
  mDN = s->RefDN();
  mVO = s->RefVO();
  mRole = s->RefRole();
  mGroup = s->RefGroup();
  mServerUsername = s->RefServerUsername();
  mFromHost = s->RefFromHost();
  mFromDomain = s->RefFromDomain();
  mProtocol = s->RefProtocol();
  mAppInfo = s->RefAppInfo();
  mLoginTime = s->RefLoginTime().GetSec();
  bNumericHost = s->GetNumericHost();
}
