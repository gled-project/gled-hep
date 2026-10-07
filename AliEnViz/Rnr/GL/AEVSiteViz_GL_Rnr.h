// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef AliEnViz_AEVSiteViz_GL_RNR_H
#define AliEnViz_AEVSiteViz_GL_RNR_H

#include <Glasses/AEVSiteViz.h>
#include <Rnr/GL/ZNode_GL_Rnr.h>

namespace gled {

class AEVSiteViz_GL_Rnr : public ZNode_GL_Rnr {
private:
  void _init();

protected:
  AEVSiteViz*	mAEVSiteViz;

public:
  AEVSiteViz_GL_Rnr(AEVSiteViz* idol) : ZNode_GL_Rnr(idol), mAEVSiteViz(idol) { _init(); }

  virtual void Draw(RnrDriver* rd);

}; // endclass AEVSiteViz_GL_Rnr

} // endnamespace gled

#endif
