// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "AEVSiteList.h"
using namespace gled;
#include "AEVSiteList.c7"

#include "AEVSite.h"

// AEVSiteList

//______________________________________________________________________________
//
//

//==============================================================================

void AEVSiteList::_init()
{
  SetElementFID(AEVSite::FID());
}

AEVSiteList::AEVSiteList(const Text_t* n, const Text_t* t) :
  ZNameMap(n, t)
{
  _init();
}

AEVSiteList::~AEVSiteList()
{}

//==============================================================================

AEVSite* AEVSiteList::FindSite(const TString& name)
{
  return dynamic_cast<AEVSite*>(GetElementByName(name));
}
