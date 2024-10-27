CXX=clang++
CXX_FLAGS=-std=c++20 -I ./includes -Wall -Wextra -Werror -pedantic -g

SRC := $(wildcard ./src/lib/*.cc)
HDRS := $(wildcard ./includes/*.hpp)

exec: bin/exec

bin/exec: ./src/driver.cc $(SRC) $(HDRS) 
	$(CXX) $(CXX_FLAGS) ./src/driver.cc $(SRC) -o $@

sanitize: bin/sanitize

bin/sanitize: ./src/driver.cc $(SRC) $(HDRS)
	$(CXX) $(CXX_FLAGS) -fsanitize=address -fno-omit-frame-pointer ./src/driver.cc $(SRC) -o $@
# Address Sanitizer (aSan) = -fsanitize=address
# Undefined Behavior Sanitizer (uBSan) = -fsanitize=undefined
# Valgrind (just memcheck) = -g -fstandalone-debug
# 	valgrind --tool=memcheck --leak-check=full ./bin/sanitize


.DEFAULT_GOAL := exec
.PHONY: exec clean

clean:
	rm -rf bin/* && rm -rf obj/*
