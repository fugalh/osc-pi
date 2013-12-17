# OSCπ

Control your [Raspberry Pi](http://www.raspberrypi.org/)
with [OSC](http://opensoundcontrol.org/).

## Synopsis

Run `osc-pi` on your RPi, then send it OSC messages. The default port is 7433
(tree) and it responds to the following messages:
- `/set i $pin`
- `/clear i $pin`

Where `$pin` is the GPIO number, not the RPi's P1 pin number. (i.e. 4 not 7)
![Raspberry Pi pinout](http://pingig.com/sites/default/files/raspberrypirev2pinout.jpg)

## Requirements
- A Raspberry Pi revision 2. (It's probably not difficult to support v1, send
  me an email if you need that).
- [liblo >= 0.28rc](http://liblo.sourceforge.net/).
  To build liblo 0.28rc on Raspbian which defaults to gcc 4.6, see
  [liblo-gcc46.patch](https://raw.github.com/fugalh/osc-pi/master/liblo_gcc46.patch).
  The Raspbian package liblo-dev is too old.
- [bcm2835](http://www.airspayce.com/mikem/bcm2835/index.html). (Tested with version 1.34)
- For running the tests only, you need [gmock](https://code.google.com/p/googlemock/).
  I only do this on my laptop.

Tested with the default g++ on Raspbian which is currently gcc 4.6.

Building should be as simple as installing the two dependencies
(`./configure; make; make install` in their respective directories)
and then typing `make`.

The makefile isn't full-blown autoconf or anything quite that smart, but it
should be easy enough to tweak to use your include paths if you install the
dependencies somewhere weird.

## Future directions
Because you often don't have a lot of control over the structure of the
messages you can send from an OSC gui builder (e.g.
[TouchOSC](http://hexler.net/software/touchosc)) or
[Control](http://charlie-roberts.com/Control/), it will need to be easier to
set up custom OSC paths. Maybe a config file. Maybe just an easily-edited
function. There shall be refactoring!

Either way, there's a need to flesh out the OSC messages we accept.

## License
I haven't decided yet. Something open source. If you're going to distribute it
and you're concerned send me an email.
