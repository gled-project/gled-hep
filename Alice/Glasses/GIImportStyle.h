// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_GIImportStyle_H
#define Alice_GIImportStyle_H

#include <Glasses/ZGlass.h>

namespace gled {

class GIImportStyle : public ZGlass {
  MAC_RNR_FRIENDS(GIImportStyle);

 private:
  void _init();

 protected:

 public:
  Bool_t    mImportKine;   // X{GS} 7 Bool(-join=>1)
  Bool_t    mRnrKine;      // X{GS} 7 Bool()

  Bool_t    mImportHits;   // X{GS} 7 Bool(-join=>1)
  Bool_t    mRnrHits;      // X{GS} 7 Bool()

  Bool_t    mImportRec;    // X{GS} 7 Bool(-join=>1)
  Bool_t    mRnrRec;       // X{GS} 7 Bool()

  Bool_t    mImportClusters; // X{GS} 7 Bool(-join=>1)
  Bool_t    mRnrClusters;    // X{GS} 7 Bool()

  GIImportStyle(const Text_t* n="GIImportStyle", const Text_t* t=0) :
    ZGlass(n,t) { _init(); }

#include "GIImportStyle.h7"
  ClassDef(GIImportStyle, 1)
    }; // endclass GIImportStyle

} // endnamespace gled

#endif
