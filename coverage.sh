#!/bin/bash
clang++  -fprofile-instr-generate -fcoverage-mapping main.cpp -o main

for i in `seq 1 1000`;
do
    LLVM_PROFILE_FILE="profraw/$i.profraw" ./main < testFiles/$i.txt
done  

LLVM_PROFILE_FILE="profraw/squares.profraw" ./main < testFiles/squares.txt
LLVM_PROFILE_FILE="profraw/rectangles.profraw" ./main < testFiles/rectangles.txt
LLVM_PROFILE_FILE="profraw/trapezoids.profraw" ./main < testFiles/trapezoids.txt
LLVM_PROFILE_FILE="profraw/rhombus.profraw" ./main < testFiles/rhombus.txt
LLVM_PROFILE_FILE="profraw/parallelograms.profraw" ./main < testFiles/parallelograms.txt

str=""
for i in `seq 1 1000`;
do
    str+="profraw/$i.profraw "
done
str+="profraw/squares.profraw "
str+="profraw/rectangles.profraw "
str+="profraw/trapezoids.profraw "
str+="profraw/rhombus.profraw "
str+="profraw/parallelograms.profraw"

xcrun llvm-profdata merge -sparse $str -o coverage.profdata
	xcrun llvm-cov show ./main -instr-profile=coverage.profdata > coverage.txt


for i in `seq 1 1000`;
do
    rm -f "profraw/$i.profraw"
    
done  

rm -f profraw/squares.profraw
rm -f profraw/rectangles.profraw
rm -f profraw/trapezoids.profraw
rm -f profraw/rhombus.profraw
rm -f profraw/parallelograms.profraw
