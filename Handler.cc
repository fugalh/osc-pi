#include "Handler.h"

#include <bcm2835.h>
#include <lo/lo_cpp.h>
#include "RPi.h"

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

Handler::Handler(lo::Server* osc, RPi* pi) : osc_(osc), pi_(pi)
{
  for (auto pin : pins)
  {
    pi_->gpio_output(pin);
  }

  osc_->add_method("/set", "i",
    [this](lo::Message msg) {
      pi_->gpio_set(msg.argv()[0]->i);
    });
  osc_->add_method("/clear", "i",
    [this](lo::Message msg) {
      pi_->gpio_clr(msg.argv()[0]->i);
    });
  osc_->add_method("/gpio/4", "i",
    [this](lo::Message msg) {
      if (msg.argv()[0]->i > 0)
        pi_->gpio_set(4);
      else
        pi_->gpio_clr(4);
    });
}

Handler::~Handler()
{
  osc_->del_method("/set", "i");
  osc_->del_method("/clear", "i");
}
