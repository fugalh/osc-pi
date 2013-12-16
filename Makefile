CXXFLAGS=-std=c++11
CPPFLAGS=-g -I/usr/local/include -I/opt/local/include
LDFLAGS=-L/usr/local/lib -L/opt/local/lib
LDLIBS=-lstdc++ -lbcm2835 -llo

runtest: test
	./test

test: test.o RPi.o Handler.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -lgmock -lgtest -lgmock_main -o $@

.PHONY: clean

clean:
	rm -f *.o test
