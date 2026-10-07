// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef AliEnViz_AEVSphereSSpace_H
#define AliEnViz_AEVSphereSSpace_H

#include <Glasses/SMorph.h>
#include <AliEnViz/AEVSSpace_ABase.h>

namespace gled {

class AEVSite;

class AEVSphereSSpace : public SMorph, public AEVSSpace_ABase
{
  MAC_RNR_FRIENDS(AEVSphereSSpace);

private:
  void _init();

protected:

public:
  AEVSphereSSpace(const Text_t* n="AEVSphereSSpace", const Text_t* t=0) :
    SMorph(n,t) { _init(); }

  virtual Bool_t ImportSite(AEVSite* site, Bool_t warn=false); // X{E} C{1}
  virtual void   ClearSiteVizes() {}

#include "AEVSphereSSpace.h7"
  ClassDef(AEVSphereSSpace, 1);
}; // endclass AEVSphereSSpace

} // endnamespace gled

#endif
