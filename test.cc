#include <gmock/gmock.h>
#include "RPi.h"
#include "Handler.h"

using namespace ::testing;

struct RPiMock : public RPi
{
  RPiMock() : RPi(true)
  {
    bcm2835_set_debug(1);
  }
  ~RPiMock() {}

  MOCK_METHOD2(gpio_fsel, void(uint8_t pin, uint8_t mode));
  MOCK_METHOD1(gpio_set, void(uint8_t pin));
  MOCK_METHOD1(gpio_clr, void(uint8_t pin));
};

TEST(RPi, gpio_fsel)
{
  RPiMock pi;

  EXPECT_CALL(pi, gpio_fsel(4, BCM2835_GPIO_FSEL_INPT));
  EXPECT_CALL(pi, gpio_fsel(2, BCM2835_GPIO_FSEL_OUTP));

  pi.gpio_input(4);
  pi.gpio_output(2);
}

TEST(RPi, gpio_setclr)
{
  NiceMock<RPiMock> pi;
  pi.gpio_output(4);

  EXPECT_CALL(pi, gpio_set(4));
  EXPECT_CALL(pi, gpio_clr(4));

  pi.gpio_set(4);
  pi.gpio_clr(4);
}

TEST(Handler, sets_output)
{
  NiceMock<RPiMock> pi;

  EXPECT_CALL(pi, gpio_fsel(_, BCM2835_GPIO_FSEL_OUTP))
    .Times(8);

  Handler h(&pi);
}
