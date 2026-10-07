// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

//__________________________________________________________________________
// AEVCompElRep
//
//

#include "AEVCompElRep.h"

using namespace gled;
#include "AEVCompElRep.c7"

/**************************************************************************/

void AEVCompElRep::_init()
{
  mNSlots = mNSFree = 100;
  mSpeedFacAvg = 1; mSpeedFacSgm = 0.02;
}

/**************************************************************************/


/**************************************************************************/
