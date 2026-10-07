// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef AliEnViz_AEVProcessViz_H
#define AliEnViz_AEVProcessViz_H

#include <Glasses/WSTube.h>
#include "AEVEventBatch.h"

namespace gled {

class AEVProcessViz : public WSTube
{
  MAC_RNR_FRIENDS(AEVProcessViz);

private:
  void _init();

protected:
  ZLink<AEVEventBatch> mBatch; // X{GS} L{}

  Int_t   mEntsDone; // X{GS} 7 ValOut(-join=>1)
  Float_t mMegsDone; // X{GS} 7 ValOut()

public:
  AEVProcessViz(const Text_t* n="AEVProcessViz", const Text_t* t=0) :
    WSTube(n,t) { _init(); }

#include "AEVProcessViz.h7"
  ClassDef(AEVProcessViz, 1);
}; // endclass AEVProcessViz

} // endnamespace gled

#endif
