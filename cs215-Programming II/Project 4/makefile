Project4.out : Project4.o WordData.o
	g++ -o Project4.out Project4.o WordData.o -g

Project4.o : Project4.cpp OrderedSet.hpp WordData.h
	g++ -c Project4.cpp -g

WordData.o : WordData.cpp WordData.h
	g++ -c WordData.cpp -g

clean :
	rm -f core.* *.o Project4.out
