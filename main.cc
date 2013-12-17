#include "Handler.h"
#include "RPi.h"

#include <lo/lo_cpp.h>
#include <unistd.h>

#define PORT 7433

namespace
{
  void usage()
  {
    printf("usage: osc-pi [-d] [-p PORT]\n");
    throw std::runtime_error("usage");
  }

  struct Opts
  {
    uint16_t port { 7433 };
    bool debug { false };
  };

  Opts parseopts(int argc, char** argv) {
    Opts opts;
    char o;
    while ((o = getopt(argc, argv, "hdp:")) != -1)
    {
      switch (o)
      {
      case 'p':
        opts.port = strtol(optarg, nullptr, 10);
        if (opts.port < 1)
          usage();

        break;

      case 'd':
        opts.debug = true;
        break;

      case 'h':
      case '?':
      default:
        usage();
      }
    }
    return opts;
  }

  void on_osc_err(int num, const char* msg, const char* where)
  {
    fprintf(stderr, "%s (%s)\n", msg, where);
  }
}

int main(int argc, char** argv)
{
  Opts opts;
  try {
    opts = parseopts(argc, argv);
  } catch (std::runtime_error&) {
    return 1;
  }

  lo::Server osc(opts.port, on_osc_err);
  RPi pi(opts.debug);
  Handler h(&osc, &pi);

  printf("Listening: %s\n", osc.url().c_str());

  while (true)
    osc.recv();
}
