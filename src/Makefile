TARGET = main.o Node.o Tree.o Account.o SavingsAccount.o AccountTree.o

example: $(TARGET)
	g++ -o example $(TARGET)

main.o: main.cpp Tree.h AccountTree.h SavingsAccount.h
	g++ -c -std=c++11 main.cpp

Node.o: Node.cpp Node.h
	g++ -c -std=c++11 Node.cpp

Tree.o: Tree.cpp Tree.h
	g++ -c -std=c++11 Tree.cpp

Account.o: Account.cpp Account.h
	g++ -c -std=c++11 Account.cpp

SavingsAccount.o: SavingsAccount.cpp SavingsAccount.h
	g++ -c -std=c++11 SavingsAccount.cpp

AccountTree.o: AccountTree.cpp AccountTree.h
	g++ -c -std=c++11 AccountTree.cpp

clean:
	rm -f *.o example
