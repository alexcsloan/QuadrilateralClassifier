all: main

main: main.cpp
	clang++ main.cpp -o main

test: main
	./test.sh

clean:
	rm -f main
	rm -f coordsOutput.txt
	rm -f txtFiles/err1Output.txt
	rm -f txtFiles/err2Output.txt
	rm -f txtFiles/err3Output.txt
	rm -f txtFiles/err4Output.txt
	rm -f txtFiles/err5Output.txt
	rm -f txtFiles/err6Output.txt
	rm -f txtFiles/err7Output.txt
	rm -f txtFiles/err8Output.txt
	rm -f txtFiles/err9Output.txt
	rm -f txtFiles/err10Output.txt
	rm -f txtFiles/err11Output.txt
	rm -f txtFiles/err12Output.txt
	rm -f txtFiles/err13Output.txt
	rm -f txtFiles/err14Output.txt
	rm -f txtFiles/err15Output.txt
	rm -f txtFiles/kiteOutput.txt
	rm -f txtFiles/parallelogramOutput.txt
	rm -f txtFiles/quadrilateralOutput.txt
	rm -f txtFiles/rectangleOutput.txt
	rm -f txtFiles/rhombusOutput.txt
	rm -f txtFiles/squareOutput.txt
	rm -f txtFiles/trapezoidOutput.txt
	rm -f default.prograw
	rm -f main.profdata
	rm -f coverage.profdata
	rm -rf testFiles/*



fuzzer:
	clang++ main.cpp -o main
	chmod +x shapes.py
	./shapes.py
	chmod +x fuzz

comparison:
	clang++ -std=c++11 OliverClassifier.cpp -o oliver
	clang++ main.cpp -o main
	chmod +x comparison.py
	./comparison.py
	chmod +x comparison.sh

	

cover:
	clang++ -fprofile-instr-generate -fcoverage-mapping main.cpp -o main
	
	
	LLVM_PROFILE_FILE="profraw/err1.profraw" ./main < txtFiles/err1.txt
	LLVM_PROFILE_FILE="profraw/err2.profraw" ./main < txtFiles/err2.txt
	LLVM_PROFILE_FILE="profraw/err3.profraw" ./main < txtFiles/err3.txt
	LLVM_PROFILE_FILE="profraw/err4.profraw" ./main < txtFiles/err4.txt
	LLVM_PROFILE_FILE="profraw/err5.profraw" ./main < txtFiles/err5.txt
	LLVM_PROFILE_FILE="profraw/err6.profraw" ./main < txtFiles/err6.txt
	LLVM_PROFILE_FILE="profraw/err7.profraw" ./main < txtFiles/err7.txt
	LLVM_PROFILE_FILE="profraw/err8.profraw" ./main < txtFiles/err8.txt
	LLVM_PROFILE_FILE="profraw/err9.profraw" ./main < txtFiles/err9.txt
	LLVM_PROFILE_FILE="profraw/err10.profraw" ./main < txtFiles/err10.txt
	LLVM_PROFILE_FILE="profraw/err11.profraw" ./main < txtFiles/err11.txt
	LLVM_PROFILE_FILE="profraw/err12.profraw" ./main < txtFiles/err12.txt
	LLVM_PROFILE_FILE="profraw/err13.profraw" ./main < txtFiles/err13.txt
	LLVM_PROFILE_FILE="profraw/err14.profraw" ./main < txtFiles/err14.txt
	LLVM_PROFILE_FILE="profraw/err15.profraw" ./main < txtFiles/err15.txt


	LLVM_PROFILE_FILE="profraw/kite.profraw" ./main < txtFiles/kite.txt
	LLVM_PROFILE_FILE="profraw/parallelogram.profraw" ./main < txtFiles/parallelogram.txt
	LLVM_PROFILE_FILE="profraw/quadrilateral.profraw" ./main < txtFiles/quadrilateral.txt
	LLVM_PROFILE_FILE="profraw/rectangle.profraw" ./main < txtFiles/rectangle.txt
	LLVM_PROFILE_FILE="profraw/rhombus.profraw" ./main < txtFiles/rhombus.txt
	LLVM_PROFILE_FILE="profraw/square.profraw" ./main < txtFiles/square.txt
	LLVM_PROFILE_FILE="profraw/trapezoid.profraw" ./main < txtFiles/trapezoid.txt

	xcrun llvm-profdata merge -sparse profraw/err1.profraw profraw/err2.profraw profraw/err3.profraw profraw/err4.profraw profraw/err5.profraw profraw/err6.profraw profraw/err7.profraw profraw/err8.profraw profraw/err9.profraw profraw/err10.profraw profraw/err11.profraw profraw/err12.profraw profraw/err13.profraw profraw/err14.profraw profraw/err15.profraw profraw/kite.profraw profraw/parallelogram.profraw profraw/quadrilateral.profraw profraw/rectangle.profraw profraw/rhombus.profraw profraw/square.profraw profraw/trapezoid.profraw -o main.profdata
	xcrun llvm-cov show ./main -instr-profile=main.profdata