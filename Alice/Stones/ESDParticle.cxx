// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

//__________________________________________________________________________
// RecData
//
//

#include "ESDParticle.h"

using namespace gled;

/**************************************************************************/

void ESDParticle::_init()
{
  fSign = 0;
  fLabel = -1;
  fStatus = 0;
}

/**************************************************************************/

ESDParticle::ESDParticle(Double_t* v, Double_t* p, Int_t lab, Int_t sign)
{
  _init();
  fSign=sign;
  fLabel=lab;
  //vertex
  fV[0]= v[0];
  fV[1]= v[1];
  fV[2]= v[2];
  // momentum
  fP[0]= p[0];
  fP[1]= p[1];
  fP[2]= p[2];
}

/**************************************************************************/
