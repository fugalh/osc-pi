#pragma once

#include "RPi.h"

#include <lo/lo_cpp.h>
#include <memory>
#include <vector>

class Handler
{
public:
  Handler(lo::Server*, RPi*);
  virtual ~Handler() {}

  static std::vector<uint8_t> pins;

protected:
  RPi* pi_;
  lo::Server* losrv_;
};
