// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "SXrdFileInfo.h"
#include "Glasses/XrdFile.h"

using namespace gled;

// SXrdFileInfo

//______________________________________________________________________________
//
//

//==============================================================================

void SXrdFileInfo::Assign(const XrdFile* s)
{
  mName = s->RefName();

  mOpenTime = s->RefOpenTime().GetSec();
  mCloseTime = s->RefCloseTime().GetSec();

  mReadStats = s->RefReadStats();
  mSingleReadStats = s->RefSingleReadStats();
  mVecReadStats = s->RefVecReadStats();
  mVecReadCntStats = s->RefVecReadCntStats();
  mWriteStats = s->RefWriteStats();

  mRTotalMB = s->GetRTotalMB();
  mWTotalMB = s->GetWTotalMB();
  mSizeMB = s->GetSizeMB();
}
