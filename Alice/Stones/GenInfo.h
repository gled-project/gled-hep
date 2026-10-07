// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_GenInfo_H
#define Alice_GenInfo_H

#include <TObject.h>

namespace gled {

class GenInfo : public TObject {

 private:
  void _init();

 protected:

 public:
  Int_t        fLabel;
  Bool_t       bR;  // is reconstructed
  Bool_t       bV0; // has V0
  Bool_t       bKK; // has Kink
  Int_t        Nh;  // number of hits
  Int_t        Nc;  // number of clusters

  GenInfo(const Text_t* n="GenInfo", const Text_t* t=0) :
    TObject()
  { _init(); }
  //virtual ~GenInfo() { delete P; delete R; }

#include "GenInfo.h7"
  ClassDef(GenInfo, 1)
    }; // endclass GenInfo

} // endnamespace gled

#endif
