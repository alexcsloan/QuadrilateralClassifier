all: main

main: main.cpp
	clang++ main.cpp -o main

test: main
	./test.sh

clean:
	rm -f main
	rm -f coordsOutput.txt

cover:
	clang++ -fprofile-instr-generate -fcoverage-mapping main.cpp -o main
	LLVM_PROFILE_FILE="main.profraw" ./main < coords.txt
	xcrun llvm-profdata merge -sparse main.profraw -o main.profdata
	xcrun llvm-cov show ./main -instr-profile=main.profdata