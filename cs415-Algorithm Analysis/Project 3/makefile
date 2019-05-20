CFLAGS= -ggdb -std=c++11 -Wall -Wextra

a.x: bst.o 23.o main.o
	g++ $(CFLAGS) -o a.x bst.o 23.o main.o
    
bst.o: bst.h bst.cpp
	g++ $(CFLAGS) -c -o bst.o bst.cpp
    
23.o: 23.h 23.cpp
	g++ $(CFLAGS) -c -o 23.o 23.cpp
    
main.o: bst.h 23.h main.cpp
	g++ $(CFLAGS) -c -o main.o main.cpp
    
clean:
	rm -f *.o *.x *~
