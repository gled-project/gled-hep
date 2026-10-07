// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_RecTrack_H
#define Alice_RecTrack_H

#include <Glasses/TrackBase.h>
#include <Stones/ESDParticle.h>

namespace gled {

class RecTrack : public TrackBase {
  MAC_RNR_FRIENDS(RecTrack);

 private:
  void _init();

 protected:
  ESDParticle*             mESD;           // X{GS} 

 public:
  RecTrack(const Text_t* n="RecTrack", const Text_t* t=0) :
    TrackBase(n,t) { _init(); }

  RecTrack(ESDParticle* esd, const Text_t* n="RecTrack", const Text_t* t=0);
  virtual ~RecTrack() { delete mESD; }
  void Dump();                            // X{E} 7 MButt()

#include "RecTrack.h7"
  ClassDef(RecTrack, 1)
    }; // endclass RecTrack

} // endnamespace gled

#endif
