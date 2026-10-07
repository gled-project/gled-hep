// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_MCTrack_GL_RNR_H
#define Alice_MCTrack_GL_RNR_H

#include <Glasses/MCTrack.h>
#include <Rnr/GL/ZNode_GL_Rnr.h>
#include <RnrBase/RnrDriver.h>
#include <Rnr/GL/MCHelixLine.h>

namespace gled {

class ZAliLoad;

class MCTrack_GL_Rnr : public ZNode_GL_Rnr
{
  friend class MCTrackRnrStyle;

  typedef void (MCTrack_GL_Rnr::*RenderVertices)(ZColor& col); 

 private:

  void       _init();

  void       make_track(RnrDriver* rd);

  void       loop_points(ZColor& col);

  int        find_index(int start, float time);
  void       set_color(Float_t time, ZColor col);
  void       mark_vertex(Int_t idx, ZColor& orig_col);
  void       interpolate_vertex(Int_t idx, Float_t time, ZColor& orig_col);

  void       loop_points_and_check_time(ZColor& col);

  std::vector<MCVertex> track_points;
  RenderVertices   vertices_foo;

 protected:
  MCTrack*         mMCTrack;
  RnrModStore      mParticleRMS;

  TimeStamp_t      mStampPointCalc;

 public:
  MCTrack_GL_Rnr(MCTrack* idol) :
    ZNode_GL_Rnr(idol), mMCTrack(idol), mParticleRMS(FID_t(0,0))
  { _init(); }

  virtual void Draw(RnrDriver* rd);
  virtual void Render(RnrDriver* rd);

}; // endclass MCTrack_GL_Rnr

} // endnamespace gled

#endif
