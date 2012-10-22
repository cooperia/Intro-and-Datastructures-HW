main: main.cpp  opnode.o opstack.o numstack.o numnode.o
	g++ main.cpp opnode.o opstack.o numnode.o numstack.o -o calc

opnode.o: opnode.cpp opnode.h
	g++ -c opnode.cpp

opstack.o: opstack.cpp opstack.h
	g++ -c opstack.cpp

numnode.o: numnode.cpp numnode.h
	g++ -c numnode.cpp

numstack.o: numstack.cpp numstack.h
	g++ -c numstack.cpp

clean:
	rm -f a.out *.o
