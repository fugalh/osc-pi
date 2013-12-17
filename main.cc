#include "Handler.h"
#include "RPi.h"

#include <lo/lo_cpp.h>

#define PORT 7433

namespace {
  void on_osc_err(int num, const char* msg, const char* where)
  {
    fprintf(stderr, "%s (%s)\n", msg, where);
  }
}

int main(void) {
  lo::Server osc(PORT, on_osc_err);

  RPi pi(true);

  Handler h(&osc, &pi);

  while (true)
    osc.recv();
}
