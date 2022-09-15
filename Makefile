CC = g++ -g3 -g -std=c++11 

Ask1: main.o book.o library.o

	$(CC) -o Ask1 main.o library.o book.o -lm

main.o: main.cpp library.cpp book.cpp

	$(CC) -c main.cpp book.cpp library.cpp 

book.o: book.cpp

	$(CC) -c book.cpp

library.o: library.cpp

	$(CC) -c library.cpp

run:

	./Ask1 500 1000 300 200

valgrind:

	valgrind --leak-check=yes ./Ask1 5 15 10 10

clean: 

	rm -f *.o

	