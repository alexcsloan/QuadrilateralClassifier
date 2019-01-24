all: main

sud: main.cpp
	clang++ main.cpp -o main

test: sud
	./test.sh

clean:
	rm -f sud