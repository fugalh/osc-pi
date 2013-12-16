#pragma once
// http://www.airspayce.com/mikem/bcm2835/
#include <bcm2835.h>

class RPi
{
public:
  RPi();
  virtual ~RPi();

  virtual void gpio_set(uint8_t pin);
  virtual void gpio_clr(uint8_t pin);
  virtual void gpio_fsel(uint8_t pin, uint8_t mode);

  void gpio_output(uint8_t pin);
  void gpio_input(uint8_t pin);

protected:
  RPi(bool forTesting);
};
