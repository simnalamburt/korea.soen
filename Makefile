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
	@echo ''

build: src/main.cpp src/main.h
	@mkdir -p target
	@g++ -std=c++0x src/main.cpp -o target/main

run: build
	@target/main

clean:
	@rm -rf target
