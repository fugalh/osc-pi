# OSCπ

Control your [Raspberry Pi](http://www.raspberrypi.org/)
with [OSC](http://opensoundcontrol.org/).

## Synopsis

Run osc-pi on your pi, then send it OSC messages. The default port is 7433
(tree) and it responds to the following messages:
- `/set i $pin`
- `/clear i $pin`

Where `$pin` is the pi's pin number, not the gpio number.

## Requirements
- A Raspberry Pi 2. (It's probably not difficult to support v1, send me an
  email if you need that).
- [liblo >= 0.28rc](http://liblo.sourceforge.net/)
  To build liblo 0.28rc on Raspbian which defaults to gcc 4.6, see
  [liblo-gcc46.patch](https://raw.github.com/fugalh/osc-pi/master/liblo_gcc46.patch).
  The Raspbian package liblo-dev is too old.
- [bcm2835](http://www.airspayce.com/mikem/bcm2835/index.html)
- For testing only, you need [gmock](https://code.google.com/p/googlemock/).
  I do this on my laptop only.

Tested with the default g++ on Raspbian which is currently gcc 4.6.

Building should be as simple as installing the two dependencies
(`./configure; make; make install` in their respective directories)
and then typing `make`.

The makefile isn't full-blown autoconf or anything quite that smart, but it
should be easy enough to tweak to use your include paths if you install the
dependencies somewhere weird.

## License
I haven't decided yet. Something open source. If you're going to distribute it
and you're concerned send me an email.
