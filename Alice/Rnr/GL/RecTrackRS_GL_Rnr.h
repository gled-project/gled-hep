// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_RecTrackRS_GL_RNR_H
#define Alice_RecTrackRS_GL_RNR_H

#include <Glasses/RecTrackRS.h>
#include <Rnr/GL/ZRnrModBase_GL_Rnr.h>

namespace gled {

class RecTrackRS_GL_Rnr : public ZRnrModBase_GL_Rnr {
private:
  void _init();

protected:
  RecTrackRS*	mRecTrackRS;

public:
  RecTrackRS_GL_Rnr(RecTrackRS* idol) :
    ZRnrModBase_GL_Rnr(idol), mRecTrackRS(idol)
  { _init(); }

  virtual void PreDraw(RnrDriver* rd);
  virtual void Draw(RnrDriver* rd);
  virtual void PostDraw(RnrDriver* rd);

}; // endclass RecTrackRS_GL_Rnr

} // endnamespace gled

#endif
