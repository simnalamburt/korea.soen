all:
	@echo 'Makefile'
	@echo ''
	@echo 'Usage:'
	@echo '    make <command>'
	@echo ''
	@echo 'Commands are:'
	@echo '    build       Compile the current project'
	@echo '    clean       Remove the target directory'
	@echo '    run         Build and excute src/main.cpp'
	@echo '    test        Run the tests'
	@echo ''

build: src/main.cpp src/book.cpp src/book.h
	@mkdir -p target
	@g++ -std=c++0x src/main.cpp src/book.cpp -o target/main

run: build
	@target/main

test: build tests/test.cpp tests/unittest.cpp src/book.cpp src/book.h
	@mkdir -p target
	@g++ -std=c++0x tests/test.cpp src/book.cpp -o target/test
	@g++ -std=c++0x tests/unittest.cpp src/book.cpp -o target/unittest
	@target/test
	@target/unittest

clean:
	@rm -rf target
