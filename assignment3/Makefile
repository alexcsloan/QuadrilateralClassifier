all: main

main: main.cpp
	clang++ main.cpp -std=cpp11 -o main

test: main
	./test.sh

clean:
	rm -f main