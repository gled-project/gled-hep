// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef AliEnViz_AEVMapViz_GL_RNR_H
#define AliEnViz_AEVMapViz_GL_RNR_H

#include <Glasses/AEVMapViz.h>
#include <Rnr/GL/ZNode_GL_Rnr.h>

namespace gled {

class AEVMapViz_GL_Rnr : public ZNode_GL_Rnr {
private:
  void _init();

protected:
  AEVMapViz*	mAEVMapViz;

public:
  AEVMapViz_GL_Rnr(AEVMapViz* idol) : ZNode_GL_Rnr(idol), mAEVMapViz(idol)
  { _init(); }

  /*
  virtual void PreDraw(RnrDriver* rd);
  virtual void Draw(RnrDriver* rd);
  virtual void PostDraw(RnrDriver* rd);
  */

}; // endclass AEVMapViz_GL_Rnr

} // endnamespace gled

#endif
