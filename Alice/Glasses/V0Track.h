// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_V0Track_H
#define Alice_V0Track_H

#include <Glasses/RecTrack.h>

namespace gled {

class V0Track : public RecTrack {
  MAC_RNR_FRIENDS(V0Track);

 private:
  void _init();

 protected:

 public:
  Double_t mVM[3];
  Float_t  mVP[3];
  V0Track(const Text_t* n="V0Track", const Text_t* t=0) :
    RecTrack(n,t) { _init(); }
  V0Track(ESDParticle* esd, const Text_t* n="RecTrack", const Text_t* t=0);

#include "V0Track.h7"
  ClassDef(V0Track, 1)
    }; // endclass V0Track

} // endnamespace gled

#endif
