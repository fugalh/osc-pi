#include "RPi.h"
#include <bcm2835.h>

RPi::RPi(bool debug)
{
  bcm2835_set_debug(debug);
  bcm2835_init();
}

RPi::~RPi()
{
  bcm2835_close();
}

void RPi::gpio_set(uint8_t pin)
{
  bcm2835_gpio_set(pin);
}

void RPi::gpio_clr(uint8_t pin)
{
  bcm2835_gpio_clr(pin);
}

void RPi::gpio_fsel(uint8_t pin, uint8_t mode)
{
  bcm2835_gpio_fsel(pin, mode);
}

void RPi::gpio_output(uint8_t pin)
{
  gpio_fsel(pin, BCM2835_GPIO_FSEL_OUTP);
}

void RPi::gpio_input(uint8_t pin)
{
  gpio_fsel(pin, BCM2835_GPIO_FSEL_INPT);
}

void RPi::set_debug(bool b)
{
  bcm2835_set_debug(b);
}
