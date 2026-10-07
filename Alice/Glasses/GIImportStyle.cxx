// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

//__________________________________________________________________________
// GIImportStyle
//
//

#include "GIImportStyle.h"
using namespace gled;
#include "GIImportStyle.c7"

/**************************************************************************/

  void GIImportStyle::_init()
{
  // *** Set all links to 0 ***
  mImportKine = true;
  mImportHits=true;
  mImportClusters=true;
  mImportRec = true;
  mRnrKine = true;
  mRnrHits = true;
  mRnrClusters = true;
  mRnrRec = true;
}

/**************************************************************************/


/**************************************************************************/
