all: ./a.out

compRun:
	g++ -std=c++11 person.cpp main.cpp persons.cpp -o r.o


run: clean compRun; ./r.o

clean:
	rm -f *.o