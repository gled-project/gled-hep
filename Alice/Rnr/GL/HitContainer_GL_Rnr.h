// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_HitContainer_GL_RNR_H
#define Alice_HitContainer_GL_RNR_H

#include <Glasses/HitContainer.h>
#include <Rnr/GL/ZNode_GL_Rnr.h>

namespace gled {

class HitContainer_GL_Rnr : public ZNode_GL_Rnr {
private:
  void _init();

protected:
  HitContainer*	mHitContainer;

public:
  HitContainer_GL_Rnr(HitContainer* idol) :
    ZNode_GL_Rnr(idol), mHitContainer(idol)
  { _init(); }

 
  virtual void Draw(RnrDriver* rd);

}; // endclass HitContainer_GL_Rnr

} // endnamespace gled

#endif
