// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef AliEnViz_AEVSSpace_ABase_H
#define AliEnViz_AEVSSpace_ABase_H

#include <Rtypes.h>

namespace gled {

class AEVSite;

class AEVSSpace_ABase
{
public:
  virtual ~AEVSSpace_ABase() {}

  virtual Bool_t ImportSite(AEVSite* site, Bool_t warn=false) = 0;
  virtual void   ClearSiteVizes() {}

  ClassDef(AEVSSpace_ABase, 0); // Abstract interface - site-management API for space representations.
}; // endclass AEVSSpace_ABase

} // endnamespace gled

#endif
