// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_RecTrackRS_H
#define Alice_RecTrackRS_H

#include <Glasses/PRSBase.h>
#include <Stones/ZColor.h>

namespace gled {

class RecTrackRS : public PRSBase
{
  MAC_RNR_FRIENDS(RecTrackRS);

 private:
  void _init();

 public:
  Bool_t      bFitKinks;      // X{GST}  7 Bool( -join=>1)
  Bool_t      bFitV0;         // X{GST}  7 Bool()
  Float_t     mKinkVSize;     // X{GST}  7 Value(-range=>[0.1,64, 1,10])
  ZColor      mKinkVColor;    // X{PGST} 7 ColorButt()

 public:
  RecTrackRS(const Text_t* n="RecTrackRS", const Text_t* t=0) :
    PRSBase(n,t) { _init(); }

#include "RecTrackRS.h7"
  ClassDef(RecTrackRS, 1)
}; // endclass RecTrackRS

} // endnamespace gled

#endif
