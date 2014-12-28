all: src/main.cpp
	g++ -std=c++0x src/main.cpp

clean:
	rm -f a.out
