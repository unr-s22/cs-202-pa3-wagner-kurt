executable: main.cpp Money.o Account.o
	g++ -Werror main.cpp Money.o Account.o -o executable
Money.o: Money.cpp Money.h
	g++ -c Money.cpp
Account.o: Account.cpp Account.h
	g++ -c Account.cpp
clean:
	rm -f executable *.o
