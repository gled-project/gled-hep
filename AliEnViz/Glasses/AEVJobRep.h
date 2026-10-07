// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef AliEnViz_AEVJobRep_H
#define AliEnViz_AEVJobRep_H

#include <Glasses/ZGlass.h>

namespace gled {

class AEVJobRep : public ZGlass
{
  MAC_RNR_FRIENDS(AEVJobRep);
  friend class AEVMlClient;

private:
  void _init();

protected:
  TString   mJobname;	// X{GS} 7 TextOut()
  TString   mUsername;	// X{GS} 7 TextOut()
  TString   mStatus;	// X{GS} 7 TextOut()
  TString   mDateStr;	// X{GS} 7 TextOut()

public:
  AEVJobRep(const Text_t* n="AEVJobRep", const Text_t* t=0) :
    ZGlass(n,t) { _init(); }

  void FormatTitle();

#include "AEVJobRep.h7"
  ClassDef(AEVJobRep, 1);
}; // endclass AEVJobRep

} // endnamespace gled

#endif
