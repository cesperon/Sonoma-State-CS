wI.out: weaponInventory.o
	g++ -std=c++11  -g -o wI.out weaponInventory.o

weaponInventory.o: weaponInventory.cpp
	g++ -std=c++11  -g -c weaponInventory.cpp

clean:
	rm -f *.o wI.out

run : wI.out
	clear
	./wI.out
