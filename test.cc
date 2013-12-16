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

class TServer : public lo::Server
{
public:
  static void on_err(int num, const char* msg, const char* where)
  {
    fprintf(stderr, "%s (%s)\n", msg, where);
  }

  TServer() : lo::Server(nullptr, on_err)
  {
    printf("%s\n", url().c_str());
  }

  using lo::Server::_handlers;
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

//////// Handler

TEST(Handler, sets_output)
{
  TServer osc;
  NiceMock<RPiMock> pi;

  EXPECT_CALL(pi, gpio_fsel(_, BCM2835_GPIO_FSEL_OUTP))
    .Times(8);

  Handler h(&osc, &pi);
}

TEST(Handler, handlers_registered_and_deregistered) {
  TServer osc;
  NiceMock<RPiMock> pi;

  {
    Handler h(&osc, &pi);

    EXPECT_THAT(osc._handlers.count("/set,i"), Eq(1));
    EXPECT_THAT(osc._handlers.count("/clear,i"), Eq(1));
  }

  EXPECT_THAT(osc._handlers.count("/set,i"), Eq(0));
  EXPECT_THAT(osc._handlers.count("/clear,i"), Eq(0));
}

/*
TEST(Handler, handles_set)
{
  NiceMock<RPiMock> pi;
  Handler h(&pi);

  EXPECT_CALL(pi, gpio_set(RPI_V2_GPIO_P1_07));

  osc.emit("/set", RPI_V2_GPIO_P1_07);
}

TEST(Handler, handles_clear)
{
  NiceMock<RPiMock> pi;
  Handler h(&pi);

  EXPECT_CALL(pi, gpio_clr(RPI_V2_GPIO_P1_07));

  osc.emit("/clear", RPI_V2_GPIO_P1_07);
}
*/
