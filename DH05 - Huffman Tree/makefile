main: main.cpp huffman.o bitstream.o
	g++ main.cpp huffman.o bitstream.o -o hzip
	ln -sf hzip hunzip

huffman.o: huffman.cpp huffman.h
	g++ -c huffman.cpp

clean:
	rm -f a.out *.o