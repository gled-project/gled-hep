// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "RecTrackRS_GL_Rnr.h"
#include <RnrBase/RnrDriver.h>
#include <GL/glew.h>

using namespace gled;

#define PARENT ZRnrModBase_GL_Rnr

/**************************************************************************/

void RecTrackRS_GL_Rnr::_init()
{}

/**************************************************************************/

void RecTrackRS_GL_Rnr::PreDraw(RnrDriver* rd)
{
  PARENT::PreDraw(rd);
  update_tring_stamp(rd);
  rd->PushRnrMod(RecTrackRS::FID(),  mRnrMod);
}

void RecTrackRS_GL_Rnr::Draw(RnrDriver* rd)
{
  update_tring_stamp(rd);
  rd->SetDefRnrMod(RecTrackRS::FID(), mRnrMod);
}

void RecTrackRS_GL_Rnr::PostDraw(RnrDriver* rd)
{
  rd->PopRnrMod(RecTrackRS::FID());
  PARENT::PostDraw(rd);
}
