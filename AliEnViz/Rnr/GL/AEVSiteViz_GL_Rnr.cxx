// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "AEVSiteViz_GL_Rnr.h"
#include <Rnr/GL/SphereTrings.h>
#include <GL/glew.h>

using namespace gled;

/**************************************************************************/

void AEVSiteViz_GL_Rnr::_init()
{}

/**************************************************************************/

void AEVSiteViz_GL_Rnr::Draw(RnrDriver* rd)
{
  AEVSiteViz& A = *mAEVSiteViz;

  glColor4fv(A.mColor());
  glPushMatrix();
  glScalef(0.5, 0.5, 0.5);
  SphereTrings::EnableGL(2);
  SphereTrings::DrawAndDisableGL(2);
  glPopMatrix();
}
