// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_KinkTrack_H
#define Alice_KinkTrack_H

#include <Glasses/TrackBase.h>
#include <Stones/Kink.h>
 
namespace gled {

class KinkTrack : public TrackBase
{
  MAC_RNR_FRIENDS(KinkTrack);

 private:
  void _init();

 protected:
  Kink*             mKink;           // X{GS} 

 public:
  KinkTrack(const Text_t* n="KinkTrack", const Text_t* t=0) :
    TrackBase(n,t) { _init(); }

  KinkTrack(Kink* kink, const Text_t* n="KinkTrack", const Text_t* t=0);
  virtual ~KinkTrack() { delete mKink; }

#include "KinkTrack.h7"
  ClassDef(KinkTrack, 1)
}; // endclass KinkTrack

} // endnamespace gled

#endif
