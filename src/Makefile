example: main.o Node.o Tree.o
	g++ -o example main.o Node.o Tree.o

main.o: main.cpp Tree.h
	g++ -c main.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Tree.o: Tree.cpp Tree.h
	g++ -c Tree.cpp

clean:
	rm -f *.o example
