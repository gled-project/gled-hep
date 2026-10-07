// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "MCTrackRnrStyle_GL_Rnr.h"
#include <RnrBase/RnrDriver.h>
#include <GL/glew.h>

using namespace gled;

/**************************************************************************/

void MCTrackRnrStyle_GL_Rnr::_init()
{}

/**************************************************************************/

void MCTrackRnrStyle_GL_Rnr::PreDraw(RnrDriver* rd)
{
  update_tring_stamp(rd);
  mTRS->calculate_abs_times();
  rd->PushRnrMod(MCTrackRnrStyle::FID(),  mRnrMod);
}

void MCTrackRnrStyle_GL_Rnr::Draw(RnrDriver* rd)
{
  update_tring_stamp(rd);
  mTRS->calculate_abs_times();
  rd->SetDefRnrMod(MCTrackRnrStyle::FID(), mRnrMod);
}

void MCTrackRnrStyle_GL_Rnr::PostDraw(RnrDriver* rd)
{
  rd->PopRnrMod(MCTrackRnrStyle::FID());
}
