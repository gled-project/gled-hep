// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

//__________________________________________________________________________
// Hit
//
//

#include "Hit.h"

using namespace gled;

/**************************************************************************/

Hit::Hit(UChar_t Detector, Int_t Particle, Int_t Eva, Float_t X, Float_t Y, Float_t Z ):TObject()
{ 
  fDetID=Detector;
  fLabel=Particle;
  fEvaLabel=Eva;
  x=X;y=Y;z=Z;
}

/**************************************************************************/

void Hit::Print(Option_t* option) const
{
  printf("XYZ(%f,%f,%f) eva(%d) label(%d) det(%d) \n",
	 x,y,z,fEvaLabel, fLabel, fDetID);
}

/**************************************************************************/
