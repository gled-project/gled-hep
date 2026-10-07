// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

//__________________________________________________________________________
// AEVSiteViz
//
//

#include "AEVSiteViz.h"
using namespace gled;
#include "AEVSiteViz.c7"

/**************************************************************************/

void AEVSiteViz::_init()
{
  // ZNode::OM stuffe
  bUseOM = true; mOM = 0;

  mColor.rgba(0.6, 0, 0.6);
}

/**************************************************************************/


/**************************************************************************/
