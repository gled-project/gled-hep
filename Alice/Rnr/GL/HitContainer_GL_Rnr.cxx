// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "HitContainer_GL_Rnr.h"
#include <GL/glew.h>

using namespace gled;

/**************************************************************************/

void HitContainer_GL_Rnr::_init()
{}

/**************************************************************************/

void HitContainer_GL_Rnr::Draw(RnrDriver* rd)
{
  HitContainer&	HC = *mHitContainer;
  if(HC.mNPoints > 0) {

    if(HC.mSize > 0) glPointSize(HC.mSize);
    glColor4fv(mHitContainer->mColor());

    glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
    glVertexPointer(3, GL_FLOAT, 0, HC.mPoints);
    glEnableClientState(GL_VERTEX_ARRAY);

    glDrawArrays(GL_POINTS, 0, HC.mNPoints);
    // In selection mode should loop over points and do push/pop name.

    glPopClientAttrib();
  }
}
