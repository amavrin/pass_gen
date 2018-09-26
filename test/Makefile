all: clean test

test: runner

runner: pasgen_test.h
	cxxtestgen --error-printer -o runner.cpp pasgen_test.h
	g++ -std=c++11 -o runner runner.cpp
	./runner

clean:
	rm -f runner
