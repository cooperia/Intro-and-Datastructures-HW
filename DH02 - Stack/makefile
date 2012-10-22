main: main.cpp  numnode.o numstack.o
	g++ main.cpp numnode.o numstack.o -o listStats

numnode.o: numnode.cpp numnode.h
	g++ -c numnode.cpp

numstack.o: numstack.cpp numstack.h
	g++ -c numstack.cpp

clean:
	rm -f a.out *.o
