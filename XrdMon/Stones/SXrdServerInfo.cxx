// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "SXrdServerInfo.h"
#include "Glasses/XrdServer.h"

using namespace gled;

// SXrdServerInfo

//______________________________________________________________________________
//
//

//==============================================================================

void SXrdServerInfo::Assign(const XrdServer* s)
{
  mHost   = s->RefHost();
  mDomain = s->RefDomain();
  mSite   = s->RefSite();
}
