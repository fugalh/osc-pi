CXXFLAGS=-std=c++0x
CPPFLAGS=-g -I/usr/local/include -I/opt/local/include
LDFLAGS=-L/usr/local/lib -L/opt/local/lib
LDLIBS=-lbcm2835 -llo

osc-pi: main.o RPi.o Handler.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

runtest: test
	./test

test: test.o RPi.o Handler.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -lgmock -lgtest -lgmock_main -o $@

.PHONY: all clean

clean:
	rm -f *.o test osc-pi
