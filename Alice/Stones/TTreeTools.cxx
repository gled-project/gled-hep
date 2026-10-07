// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

//__________________________________________________________________________
// TTreeTools
//
//

#include "TTreeTools.h"

using namespace gled;

/**************************************************************************/
/**************************************************************************/

#include <TTreeFormula.h>

TSelectorToEventList::TSelectorToEventList(TEventList* evl, const Text_t* sel) :
  TSelectorDraw(), fEvList(evl)
{
  fInput.Add(new TNamed("varexp", ""));
  fInput.Add(new TNamed("selection", sel));
  SetInputList(&fInput);
}

Bool_t TSelectorToEventList::Process(Long64_t entry)
{
  if(ProcessCut(entry)) { ProcessFill(entry); return true; }
  return false;
}

Bool_t TSelectorToEventList::ProcessCut(Long64_t entry)
{
  return GetSelect()->EvalInstance(0) != 0;
}

/**************************************************************************/
/**************************************************************************/

#include <TTree.h>

Int_t TTreeQuery::Select(TTree* t, const Text_t* selection)
{
  TSelectorToEventList sel(this, selection);
  t->Process(&sel, "goff");
  return GetN();
}
