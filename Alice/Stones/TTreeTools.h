// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_TTreeTools_H
#define Alice_TTreeTools_H

#include <TSelectorDraw.h>
#include <TEventList.h>

namespace gled {

class TTreeTools : public TObject
{
public:
  TTreeTools() : TObject() {}
  ClassDef(TTreeTools, 1)
}; // endclass TTreeTools

/**************************************************************************/
// TSelectorToEventList
/**************************************************************************/

class TSelectorToEventList : public TSelectorDraw
{
protected:
  TEventList* fEvList;
  TList       fInput;
public:
  TSelectorToEventList(TEventList* evl, const Text_t* sel);

  virtual Bool_t Process(Long64_t entry);
  virtual Bool_t ProcessCut(Long64_t entry);
  virtual void   ProcessFill(Long64_t entry) { fEvList->Enter(entry); }

  ClassDef(TSelectorToEventList, 1)
};

/**************************************************************************/
// TTreeQuery
/**************************************************************************/

class TTreeQuery : public TEventList
{
public:
  TTreeQuery() : TEventList() {}

  Int_t Select(TTree* t, const Text_t* selection);

  ClassDef(TTreeQuery, 1)
};

/**************************************************************************/
/**************************************************************************/

} // endnamespace gled

#endif
