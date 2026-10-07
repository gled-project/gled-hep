// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_TrackBase_H
#define Alice_TrackBase_H

#include <Glasses/ZNode.h>

namespace gled {

class TrackBase : public ZNode {
  MAC_RNR_FRIENDS(TrackBase);

private:
  void _init();

protected:

public:
  TString                  mV;             // X{GS}  7 TextOut()
  TString                  mP;             // X{GS}  7 TextOut()

  TrackBase(const Text_t* n="TrackBase", const Text_t* t=0) :
    ZNode(n,t) { _init(); }

#include "TrackBase.h7"
  ClassDef(TrackBase, 1)
}; // endclass TrackBase

} // endnamespace gled

#endif
