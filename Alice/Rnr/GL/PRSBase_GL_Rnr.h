// Copyright (C) Matevz Tadel.
// This file is part of Gled.
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef Alice_PRSBase_GL_RNR_H
#define Alice_PRSBase_GL_RNR_H

#include <Glasses/PRSBase.h>
#include <Rnr/GL/ZRnrModBase_GL_Rnr.h>

namespace gled {

class PRSBase_GL_Rnr : public ZRnrModBase_GL_Rnr {
private:
  void _init();

protected:
  PRSBase*	mPRSBase;

public:
  PRSBase_GL_Rnr(PRSBase* idol) :
    ZRnrModBase_GL_Rnr(idol)
  { _init(); }

  virtual void PreDraw(RnrDriver* rd);
  virtual void Draw(RnrDriver* rd);
  virtual void PostDraw(RnrDriver* rd);

}; // endclass PRSBase_GL_Rnr

} // endnamespace gled

#endif
