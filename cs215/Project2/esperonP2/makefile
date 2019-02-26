P2.out: Proj2app.o SetLimits.o CLife.o
	g++ -g -o P2.out Proj2app.o SetLimits.o CLife.o

Proj2app.o: Proj2app.cpp SetLimits.h CLife.h
	g++ -g -c Proj2app.cpp

SetLimits.o: SetLimits.cpp SetLimits.h
	g++ -g -c SetLimits.cpp

CLife.o: CLife.cpp CLife.h
	g++ -g -c CLife.cpp

clean:
	rm *.o P2.out

run : P2.out
	clear
	./P2.out

submit : Proj2app.cpp CLife.h CLife.cpp makefile README.txt
	rm -rf esperonP2
	mkdir esperonP2
	cp Proj2app.cpp esperonP2
	cp CLife.h esperonP2
	cp CLife.cpp esperonP2
	cp makefile esperonP2
	cp README.txt esperonP2
	tar cfvz esperonP2.tgz esperonP2
	cp esperonP2.tgz ~tiawatts/cs215drop
