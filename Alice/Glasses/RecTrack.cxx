// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

//__________________________________________________________________________
// RecTrack
//
//

#include "RecTrack.h"
using namespace gled;
#include "RecTrack.c7"

/**************************************************************************/

void RecTrack::_init()
{
  mESD=0;
}

/**************************************************************************/

RecTrack:: RecTrack(ESDParticle* esd, const Text_t* n, const Text_t* t) :
  TrackBase(n,t) 
{
  _init();
  mESD = esd;
  SetName(GForm("RecTrack %d",mESD->fLabel));
  mV = GForm("% 4.f, % 4.f, % 4.f",  mESD->fV[0],  mESD->fV[1], mESD->fV[2]);
  mP = GForm("% 6.3f, % 6.3f, % 6.3f", mESD->fP[0],  mESD->fP[1], mESD->fP[2]);
}

void RecTrack::Dump()
{
  printf("RecTrack %d, V(%f,%f,%F), P(%f,%f,%F) \n",mESD->fLabel, 
	 mESD->fV[0], mESD->fV[1], mESD->fV[2], 
	 mESD->fP[0], mESD->fP[1], mESD->fP[2]);
}
