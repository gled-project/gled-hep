// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef AliEnViz_AEVCompElRep_H
#define AliEnViz_AEVCompElRep_H

#include <Glasses/ZNode.h>

namespace gled {

class AEVCompElRep : public ZNode {
  MAC_RNR_FRIENDS(AEVCompElRep);

private:
  void _init();

protected:
  Int_t		mNSlots;	// X{GS} 7 Value(-range=>[0,10000,1])
  Int_t		mNSFree;	// X{GS} 7 Value(-range=>[0,10000,1])

  Float_t	mSpeedFacAvg;	// X{GS} 7 Value(-range=>[0,10,1,1000])
  Float_t	mSpeedFacSgm;	// X{GS} 7 Value(-range=>[-10,10,1,1000])

public:
  AEVCompElRep(const Text_t* n="AEVCompElRep", const Text_t* t=0) : ZNode(n,t) { _init(); }

#include "AEVCompElRep.h7"
  ClassDef(AEVCompElRep, 1);
}; // endclass AEVCompElRep

} // endnamespace gled

#endif
