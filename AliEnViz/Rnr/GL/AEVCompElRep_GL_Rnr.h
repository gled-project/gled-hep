// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef AliEnViz_AEVCompElRep_GL_RNR_H
#define AliEnViz_AEVCompElRep_GL_RNR_H

#include <Glasses/AEVCompElRep.h>
#include <Rnr/GL/ZNode_GL_Rnr.h>

namespace gled {

class AEVCompElRep_GL_Rnr : public ZNode_GL_Rnr {
private:
  void _init();

protected:
  AEVCompElRep*	mAEVCompElRep;

public:
  AEVCompElRep_GL_Rnr(AEVCompElRep* idol) : ZNode_GL_Rnr(idol), mAEVCompElRep(idol) { _init(); }

  virtual void PreDraw(RnrDriver* rd);
  virtual void Draw(RnrDriver* rd);
  virtual void PostDraw(RnrDriver* rd);

}; // endclass AEVCompElRep_GL_Rnr

} // endnamespace gled

#endif
