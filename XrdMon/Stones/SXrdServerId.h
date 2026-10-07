// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef XrdMon_SXrdServerId_H
#define XrdMon_SXrdServerId_H

#include <Gled/GledTypes.h>

namespace gled {

class SXrdServerId
{
public:
  UInt_t   ip4;
  Int_t    stod;
  UShort_t port;

public:
  SXrdServerId() { Clear(); }
  SXrdServerId(UInt_t _ip4, Int_t _stod, UShort_t _port) :
    ip4(_ip4), stod(_stod), port(_port) {}

  void Clear();

  bool operator==(const SXrdServerId& si) const
  { return ip4 == si.ip4 && stod == si.stod && port == si.port; }

#ifndef __CINT__
  struct Hash
  {
    // Initially the plan was to use CRC32 ... but this should be just as good.
    std::hash<size_t> hfoo;
    size_t operator()(const SXrdServerId& si) const
    { return hfoo((size_t) si.ip4 * (size_t) si.stod * (size_t) si.port); }
  };
#endif

  ClassDefNV(SXrdServerId, 1);
}; // endclass SXrdServerId

} // endnamespace gled

#endif
