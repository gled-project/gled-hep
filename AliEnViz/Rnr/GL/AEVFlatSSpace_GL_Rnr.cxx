// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "AEVFlatSSpace_GL_Rnr.h"
#include <RnrBase/RnrDriver.h>
#include <GL/glew.h>

using namespace gled;

/**************************************************************************/

void AEVFlatSSpace_GL_Rnr::_init()
{}

/**************************************************************************/

void AEVFlatSSpace_GL_Rnr::PreDraw(RnrDriver* rd)
{
  Board_GL_Rnr::PreDraw(rd);
}

void AEVFlatSSpace_GL_Rnr::Draw(RnrDriver* rd)
{
  Board_GL_Rnr::Draw(rd);
}

void AEVFlatSSpace_GL_Rnr::PostDraw(RnrDriver* rd)
{
  Board_GL_Rnr::PostDraw(rd);
}
