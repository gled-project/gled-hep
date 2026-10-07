// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef AliEnViz_AEVSphereSSpace_GL_RNR_H
#define AliEnViz_AEVSphereSSpace_GL_RNR_H

#include <Glasses/AEVSphereSSpace.h>
#include <Rnr/GL/SMorph_GL_Rnr.h>

namespace gled {

class AEVSphereSSpace_GL_Rnr : public SMorph_GL_Rnr {
private:
  void _init();

protected:
  AEVSphereSSpace*	mAEVSphereSSpace;

public:
  AEVSphereSSpace_GL_Rnr(AEVSphereSSpace* idol) : SMorph_GL_Rnr(idol), mAEVSphereSSpace(idol) { _init(); }

  virtual void PreDraw(RnrDriver* rd);
  virtual void Draw(RnrDriver* rd);
  virtual void PostDraw(RnrDriver* rd);

}; // endclass AEVSphereSSpace_GL_Rnr

} // endnamespace gled

#endif
