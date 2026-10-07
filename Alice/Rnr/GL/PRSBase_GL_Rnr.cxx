// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "PRSBase_GL_Rnr.h"
#include <RnrBase/RnrDriver.h>
#include <GL/glew.h>

using namespace gled;

#define PARENT ZRnrModBase_GL_Rnr

/**************************************************************************/

void PRSBase_GL_Rnr::_init()
{}

/**************************************************************************/

void PRSBase_GL_Rnr::PreDraw(RnrDriver* rd)
{
  PARENT::PreDraw(rd);
  update_tring_stamp(rd);
  rd->PushRnrMod(PRSBase::FID(),  mRnrMod);
}

void PRSBase_GL_Rnr::Draw(RnrDriver* rd)
{
  update_tring_stamp(rd);
  rd->SetDefRnrMod(PRSBase::FID(), mRnrMod);
}

void PRSBase_GL_Rnr::PostDraw(RnrDriver* rd)
{
  rd->PopRnrMod(PRSBase::FID());
  PARENT::PostDraw(rd);
}
