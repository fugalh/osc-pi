#pragma once

#include <memory>
#include <vector>

class RPi;
namespace lo { class Server; }

class Handler
{
public:
  Handler(lo::Server*, RPi*);
  virtual ~Handler();

  static std::vector<uint8_t> pins;

protected:
  RPi* pi_;
  lo::Server* osc_;
};
