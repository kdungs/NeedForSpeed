CXX=clang++
CXXFLAGS=-O3 -Wall -Werror -pedantic -std=c++11
ASMFLAGS+=-S -mllvm --x86-asm-syntax=intel

all: branching.s functions.s

%.s: %.cc
	${CXX} ${CXXFLAGS} ${ASMFLAGS} $^

clean:
	rm -f *.s
