// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_Hit_H
#define Alice_Hit_H

#include <TObject.h>
#include <TMath.h>

namespace gled {

class Hit : public TObject {
 public:
  Float_t  x,y,z;
  UChar_t  fDetID;   // X{GS} 
  Int_t    fLabel;   // X{GS} 
  Int_t    fEvaLabel;   // X{GS} 

  Hit() : TObject() {}
  Hit(UChar_t detector, Int_t particle, Int_t eva,
      Float_t x, Float_t y, Float_t z );

  /**************************************************************************/
  // methods needed for combined tree selection
  Double_t  R()            const { return TMath::Sqrt(x*x+y*y);}

  Double_t  P()            const { return TMath::Sqrt(x*x+y*y+z*z);}
  Double_t  Pt()           const { return TMath::Sqrt(x*x+y*y);}
  Double_t  Eta()          const { 
    if (TMath::Abs(P() != z)) return 0.5*TMath::Log((P()+z)/(P()-z));
    else  return 1.e30;}

  Double_t  Theta()        const { return (z==0)?TMath::PiOver2():TMath::ACos(z/P());}
  
  /**************************************************************************/
  void     Print(Option_t* option="") const override;
#include "Hit.h7"
  ClassDefOverride(Hit, 1)
    }; // endclass Hit

} // endnamespace gled

#endif
