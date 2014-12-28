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

test: build tests/unittest.cpp src/book.cpp src/book.h
	@g++ -std=c++0x tests/unittest.cpp src/book.cpp -o target/unittest
	@if target/unittest < tests/fixtures/input_unit >/dev/null; \
	  then echo 'Unit Test Passed!'; \
	  else >&2 echo 'Unit Test Failed!'; \
	fi
	@if target/main < tests/fixtures/input | diff - tests/fixtures/output >/dev/null; \
	  then echo 'Integration Test Passed!'; \
	  else >&2 echo 'Integration Test Failed!'; \
	fi

clean:
	@rm -rf target
