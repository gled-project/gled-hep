// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef AliEnViz_AEVEventBatch_GL_RNR_H
#define AliEnViz_AEVEventBatch_GL_RNR_H

#include <Glasses/AEVEventBatch.h>
#include <Rnr/GL/ZNode_GL_Rnr.h>

namespace gled {

class AEVEventBatch_GL_Rnr : public ZNode_GL_Rnr {
private:
  void _init();

protected:
  AEVEventBatch*	mAEVEventBatch;

public:
  AEVEventBatch_GL_Rnr(AEVEventBatch* idol) : ZNode_GL_Rnr(idol), mAEVEventBatch(idol) { _init(); }

  virtual void Draw(RnrDriver* rd);

}; // endclass AEVEventBatch_GL_Rnr

} // endnamespace gled

#endif
