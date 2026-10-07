
#pragma cling load("libGeom1.so")
#pragma cling load("libRootGeo.so")
#pragma cling load("libAlice.so")

using namespace gled;

{
  Gled::theOne->AssertLibSet("Geom1");
  Gled::theOne->AssertLibSet("RootGeo");
  gROOT->Macro("loadlibs.C");
  Gled::theOne->AssertLibSet("Alice");
}
