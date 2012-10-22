main: main.cpp bitstream.o
	g++ main.cpp bitstream.o -o bit-test

bitstream.o: bitstream.cpp bitstream.h
	g++ -c bitstream.cpp

clean:
	rm -f a.out *.o
