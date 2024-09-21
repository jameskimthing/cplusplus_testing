CXX=clang++
CXX_FLAGS=-std=c++20 -I ./includes -Wall -Wextra -Werror -pedantic -g

SRC := $(wildcard ./src/lib/*.cc)
HDRS := $(wildcard ./includes/*.hpp)

exec: bin/exec

bin/exec: ./src/driver.cc $(SRC) $(HDRS) 
	$(CXX) $(CXX_FLAGS) ./src/driver.cc ./src/lib/*.cc -o $@

.DEFAULT_GOAL := exec
.PHONY: exec clean

clean:
	rm -rf bin/* && rm -rf obj/*
