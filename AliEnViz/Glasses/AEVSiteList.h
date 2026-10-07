// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef AliEnViz_AEVSiteList_H
#define AliEnViz_AEVSiteList_H

#include <Glasses/ZNameMap.h>

namespace gled {

class AEVSite;

class AEVSiteList : public ZNameMap
{
  MAC_RNR_FRIENDS(AEVSiteList);

private:
  void _init();

protected:

public:
  AEVSiteList(const Text_t* n="AEVSiteList", const Text_t* t=0);
  virtual ~AEVSiteList();

  AEVSite* FindSite(const TString& name);

#include "AEVSiteList.h7"
  ClassDef(AEVSiteList, 1);
}; // endclass AEVSiteList

} // endnamespace gled

#endif
