all: src/main.cpp src/main.h
	g++ -std=c++0x src/main.cpp

clean:
	rm -f a.out
