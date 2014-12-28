all: main.cpp
	g++ -std=c++0x main.cpp

clean:
	rm -f a.out
