#pragma once

#include "RPi.h"

#include <memory>
#include <vector>

class Handler
{
public:
  Handler(RPi*);
  virtual ~Handler() {}

  static std::vector<uint8_t> pins;

protected:
  RPi* pi_;
};
