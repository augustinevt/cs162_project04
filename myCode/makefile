all: main

main: utils.o car.o carList.o main.o
	g++ -g utils.o car.o carList.o main.o -o main

main.o: main.cpp
	g++ -g -c main.cpp -o main.o

carList.o: carList.cpp
	g++ -g -c carList.cpp -o carList.o

car.o: car.cpp
	g++ -g -c car.cpp -o car.o

utils.o: utils.cpp
	g++ -g -c utils.cpp -o utils.o

clean:
	rm main car.o main.o carList.o utils.o
