// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_MCTrackRnrStyle_GL_RNR_H
#define Alice_MCTrackRnrStyle_GL_RNR_H

#include <Glasses/MCTrackRnrStyle.h>
#include <Rnr/GL/PRSBase_GL_Rnr.h>

namespace gled {

class MCTrackRnrStyle_GL_Rnr : public PRSBase_GL_Rnr {
private:
  void _init();

protected:
  MCTrackRnrStyle* mTRS;

public:
  MCTrackRnrStyle_GL_Rnr(MCTrackRnrStyle* idol) :
    PRSBase_GL_Rnr(idol), mTRS(idol)
  { _init(); }

  virtual void PreDraw(RnrDriver* rd);
  virtual void Draw(RnrDriver* rd);
  virtual void PostDraw(RnrDriver* rd);

}; // endclass MCTrackRnrStyle_GL_Rnr

} // endnamespace gled

#endif
