// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "XrdDomain.h"
using namespace gled;
#include "XrdDomain.c7"
#include "XrdServer.h"

// XrdDomain

//______________________________________________________________________________
//
//

//==============================================================================

void XrdDomain::_init()
{
  mPacketCount = mSeqIdFailCount = 0;
}

XrdDomain::XrdDomain(const Text_t* n, const Text_t* t) :
  ZNameMap(n, t)
{
  _init();
  SetElementFID(XrdServer::FID());
  SetKeepSorted(true);
}

XrdDomain::~XrdDomain()
{}

//==============================================================================

void XrdDomain::IncPacketCount()
{
  if (++mPacketCount % 100 == 0)
    Stamp(FID());
}

void XrdDomain::IncSeqIdFailCount()
{
  ++mSeqIdFailCount;
  Stamp(FID());
}
