// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef AliEnViz_AEVSiteViz_H
#define AliEnViz_AEVSiteViz_H

#include <Glasses/ZNode.h>
#include <Stones/ZColor.h>

namespace gled {

class AEVSiteViz : public ZNode
{
  MAC_RNR_FRIENDS(AEVSiteViz);

private:
  void _init();

protected:
  ZColor     mColor;      // X{PGS} 7 ColorButt()

public:
  AEVSiteViz(const Text_t* n="AEVSiteViz", const Text_t* t=0) :
    ZNode(n,t) { _init(); }
  virtual ~AEVSiteViz() {}

#include "AEVSiteViz.h7"
  ClassDef(AEVSiteViz, 1);
}; // endclass AEVSiteViz

} // endnamespace gled

#endif
