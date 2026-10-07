// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef AliEnViz_AEVSite_H
#define AliEnViz_AEVSite_H

#include <Glasses/ZGlass.h>

namespace gled {

class CosmicBall;

class AEVSite : public ZGlass
{
  MAC_RNR_FRIENDS(AEVSite);

  friend class AEVManager;
  friend class AEVAlienUI;

private:
  void _init();

protected:
  // ZGlass::mName used for siteName.
  // ZGlass::mTitle is sitename@location (unless the two are equal, then as name).

  TString	mLocation;	// X{GS} 7 TextOut()
  TString	mDomain;	// X{GS} 7 TextOut()

  // Int_t	mSiteId;	// X{GS} 7 ValOut()
  // Int_t	mMasterHostId;	// X{GS} 7 ValOut()

  Float_t	mLatitude;	// X{GS} 7 ValOut()
  Float_t	mLongitude;	// X{GS} 7 ValOut()

  Int_t         mSiteSize;      // X{GS} 7 ValOut()

  Int_t         mJobsStarted;   // X{GS} 7 ValOut()
  Int_t         mJobsRunning;   // X{GS} 7 ValOut()
  Int_t         mJobsSaving;    // X{GS} 7 ValOut()
  Int_t         mJobsDone;      // X{GS} 7 ValOut()
  Int_t         mJobsError;     // X{GS} 7 ValOut()

  Int_t         mEventsAll;     // X{GE} 7 ValOut()
  Int_t         mEventsDone;    // X{GE} 7 ValOut()
  Int_t         mEventsFrac;    // X{G}  7 ValOut()

  ZLink<CosmicBall> mBallViz;   // X{GS} L{}
  Bool_t            bBallOnStage; //!

  void set_event_frac();

public:
  AEVSite(const Text_t* n="AEVSite", const Text_t* t=0) : ZGlass(n,t) { _init(); }
  virtual ~AEVSite() {}

  void SetEventsAll(Int_t ea);
  void SetEventsDone(Int_t ed);

#include "AEVSite.h7"
  ClassDef(AEVSite, 1);
}; // endclass AEVSite

} // endnamespace gled

#endif
