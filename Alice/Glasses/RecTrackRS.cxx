// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

//__________________________________________________________________________
// RecTrackRS
//
//

#include "RecTrackRS.h"
using namespace gled;
#include "RecTrackRS.c7"

/**************************************************************************/

  void RecTrackRS::_init()
{
  // *** Set all links to 0 ***
  bFitKinks  = false;
  bFitV0     = false;
  mKinkVSize = 8;
  mKinkVColor.rgba(0.2, 0.8, 1);
}

/**************************************************************************/


/**************************************************************************/
