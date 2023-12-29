example: main.o Node.o Tree.o Account.o AccountTree.o
	g++ -o example main.o Node.o Tree.o Account.o AccountTree.o

main.o: main.cpp Tree.h
	g++ -c main.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Tree.o: Tree.cpp Tree.h
	g++ -c Tree.cpp

Account.o: Account.cpp Account.h
	g++ -c Account.cpp

AccountTree.o: AccountTree.cpp AccountTree.h
	g++ -c AccountTree.cpp

clean:
	rm -f *.o example
