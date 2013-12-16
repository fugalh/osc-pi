#include "Handler.h"

using std::vector;

vector<uint8_t> Handler::pins
{
  // TODO decide which pins specifically.
  // for now just the first 8
  RPI_V2_GPIO_P1_03,
  RPI_V2_GPIO_P1_05,
  RPI_V2_GPIO_P1_07,
  RPI_V2_GPIO_P1_08,
  RPI_V2_GPIO_P1_10,
  RPI_V2_GPIO_P1_11,
  RPI_V2_GPIO_P1_12,
  RPI_V2_GPIO_P1_13,
  /*
  RPI_V2_GPIO_P1_15,
  RPI_V2_GPIO_P1_16,
  RPI_V2_GPIO_P1_18,
  RPI_V2_GPIO_P1_19,
  RPI_V2_GPIO_P1_21,
  RPI_V2_GPIO_P1_22,
  RPI_V2_GPIO_P1_23,
  RPI_V2_GPIO_P1_24,
  RPI_V2_GPIO_P1_26,
  */
};

Handler::Handler(lo::Server* losrv, RPi* pi) : losrv_(losrv), pi_(pi)
{
  for (auto pin : pins)
  {
    pi_->gpio_output(pin);
  }
}
