// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "SXrdServerId.h"

using namespace gled;

// SXrdServerId

//______________________________________________________________________________
//
//


void SXrdServerId::Clear()
{
  ip4 = 0;
  stod = 0;
  port = 0;
}
