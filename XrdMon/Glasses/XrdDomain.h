// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef XrdMon_XrdDomain_H
#define XrdMon_XrdDomain_H

#include <Glasses/ZNameMap.h>

namespace gled {

class XrdDomain : public ZNameMap
{
  MAC_RNR_FRIENDS(XrdDomain);

private:
  void _init();

protected:
  Long64_t          mPacketCount;       //!X{G}    7 ValOut()
  Long64_t          mSeqIdFailCount;    //!X{G}    7 ValOut()

public:
  XrdDomain(const Text_t* n="XrdDomain", const Text_t* t=0);
  virtual ~XrdDomain();

  void     IncPacketCount();
  void     IncSeqIdFailCount();

#include "XrdDomain.h7"
  ClassDef(XrdDomain, 1);
}; // endclass XrdDomain

} // endnamespace gled

#endif
