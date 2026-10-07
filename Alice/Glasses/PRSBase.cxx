// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

//__________________________________________________________________________
// PRSBase
//
//

#include "PRSBase.h"
using namespace gled;
#include "PRSBase.c7"

/**************************************************************************/

Float_t PRSBase::sDefaultMagField = 0.4;

void PRSBase::_init()
{
  // *** Set all links to 0 ***/
  mMagField = sDefaultMagField;

  mVertexColor.rgba(1,0,0,1);
  mVertexSize = 5;
  mRnrP = false;
  mRnrV = false;
  mPColor.rgba(1,0,0,1);
  mPMinLen = 10;
  mPScale = 1;

  mTrackColor.rgba(1,1,0,1);
  mTrackWidth      = 1.2;
  mTrackStippleFac = 0;
  mTrackStipplePat = 0xCCCC;

  mMinP  = 0.00005;
  mTheta = 90;    mThetaOff = 90;
  mPhi   = 180;   mPhiOff   = 360;
  mMaxR  = 600;   mMaxZ     = 550;
  mMaxOrbs=2;
  mDelta  = 0.1; //calculate step size depending of helix radius
  mMinAng = 45;

  //textures
  mTexture = 0;
  mTexFactor = 200;
  mTexUCoor = 0;  mTexVCoor = 0;
}

/**************************************************************************/


/**************************************************************************/
