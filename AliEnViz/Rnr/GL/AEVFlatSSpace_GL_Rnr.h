// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef AliEnViz_AEVFlatSSpace_GL_RNR_H
#define AliEnViz_AEVFlatSSpace_GL_RNR_H

#include <Glasses/AEVFlatSSpace.h>
#include <Rnr/GL/Board_GL_Rnr.h>

namespace gled {

class AEVFlatSSpace_GL_Rnr : public Board_GL_Rnr {
private:
  void _init();

protected:
  AEVFlatSSpace*	mAEVFlatSSpace;

public:
  AEVFlatSSpace_GL_Rnr(AEVFlatSSpace* idol) : Board_GL_Rnr(idol), mAEVFlatSSpace(idol) { _init(); }

  virtual void PreDraw(RnrDriver* rd);
  virtual void Draw(RnrDriver* rd);
  virtual void PostDraw(RnrDriver* rd);

}; // endclass AEVFlatSSpace_GL_Rnr

} // endnamespace gled

#endif
