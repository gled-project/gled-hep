// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

//__________________________________________________________________________
// AEVJobRep
//
// Minimal job representation.
// Collected data from mona's ALIEN_QUERY.

#include "AEVJobRep.h"
using namespace gled;
#include "AEVJobRep.c7"

/**************************************************************************/

void AEVJobRep::_init()
{}

/**************************************************************************/

void AEVJobRep::FormatTitle()
{
  AEVJobRep::SetTitle(GForm("'%-8s' by %-8s: %-10s -- %s",
			    mJobname.Data(), mUsername.Data(), mStatus.Data(),
			    mDateStr.Data()));
}

/**************************************************************************/
