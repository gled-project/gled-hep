// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef AliEnViz_AEVDistAnRep_GL_RNR_H
#define AliEnViz_AEVDistAnRep_GL_RNR_H

#include <Glasses/AEVDistAnRep.h>
#include <Rnr/GL/ZNode_GL_Rnr.h>

namespace gled {

class AEVDistAnRep_GL_Rnr : public ZNode_GL_Rnr {
private:
  void _init();

protected:
  AEVDistAnRep*	mAEVDistAnRep;

public:
  AEVDistAnRep_GL_Rnr(AEVDistAnRep* idol) : ZNode_GL_Rnr(idol), mAEVDistAnRep(idol) { _init(); }

  // virtual void PreDraw(RnrDriver* rd);
  virtual void Draw(RnrDriver* rd);
  // virtual void PostDraw(RnrDriver* rd);

}; // endclass AEVDistAnRep_GL_Rnr

} // endnamespace gled

#endif
