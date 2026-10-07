// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_KinkTrack_GL_RNR_H
#define Alice_KinkTrack_GL_RNR_H

#include <Glasses/KinkTrack.h>
#include <Rnr/GL/ZNode_GL_Rnr.h>
#include <RnrBase/RnrDriver.h>

namespace gled {

class KinkTrack_GL_Rnr : public ZNode_GL_Rnr
{
private:
  void _init();

protected:
  KinkTrack*	mKinkTrack;
  RnrModStore	mTrackRMS;

public:
  KinkTrack_GL_Rnr(KinkTrack* idol) :
    ZNode_GL_Rnr(idol), mKinkTrack(idol), mTrackRMS(FID_t(0,0))
  { _init(); }

  virtual void PreDraw(RnrDriver* rd);
  virtual void Draw(RnrDriver* rd);
  virtual void PostDraw(RnrDriver* rd);
  virtual void Render(RnrDriver* rd);
}; // endclass KinkTrack_GL_Rnr

} // endnamespace gled

#endif
