add-nbo: main.o
	g++ -o add-nbo main.o

main.o: main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm -rf add-nbo *.o
