// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_RecTrack_GL_RNR_H
#define Alice_RecTrack_GL_RNR_H

#include <Glasses/RecTrack.h>
#include <Rnr/GL/ZNode_GL_Rnr.h>
#include <RnrBase/RnrDriver.h>

namespace gled {

class RecTrack_GL_Rnr : public ZNode_GL_Rnr
{
private:
  void _init();

protected:
  RecTrack*	mRecTrack;
  RnrModStore	mTrackRMS;

public:
  RecTrack_GL_Rnr(RecTrack* idol) :
    ZNode_GL_Rnr(idol), mRecTrack(idol), mTrackRMS(FID_t(0,0))
  { _init(); }

  virtual void Draw(RnrDriver* rd);
  virtual void Render(RnrDriver* rd);
}; // endclass RecTrack_GL_Rnr

} // endnamespace gled

#endif
