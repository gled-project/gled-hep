// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_Kink_H
#define Alice_Kink_H

#include <Stones/ESDParticle.h>

namespace gled {

class Kink : public ESDParticle
{
private:
  void _init();

public:
  Double_t fKV[3];   // reconstructed position of the kink
  Double_t fEV[3];   // end point
  Int_t    fDLabel;  // daughter label  
  Double_t fDP[3];   // daughter momentum

  Kink(const Text_t* n="Kink", const Text_t* t=0) : ESDParticle(n,t)
  { _init(); }

#include "Kink.h7"
  ClassDef(Kink, 1)
}; // endclass Kink

} // endnamespace gled

#endif
