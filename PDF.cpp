#include "PDF.h"

extern "C" {

  #ifndef WINDOWS
  __attribute__((visibility("default")))
  #endif
  SBOOL SCAPI SciterLibraryInit(ISciterAPI* psapi, SCITER_VALUE* plibobject)
  {
    _SAPI(psapi); // set reference to Sciter API provided by host application including scapp(quark)
    static sciter::om::hasset<libharu::Doc> pdf = new libharu::Doc(); // invloked once (C++ static convention)
    *plibobject = sciter::value::wrap_asset(pdf);
    return TRUE;
  }

}
