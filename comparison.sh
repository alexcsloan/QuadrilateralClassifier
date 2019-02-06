#!/bin/bash


./main < testFiles/squares.txt >> "compare/alex.txt"
./main < testFiles/rectangles.txt >> "compare/alex.txt"
./main < testFiles/trapezoids.txt >> "compare/alex.txt"
./main < testFiles/rhombus.txt >> "compare/alex.txt"
./main < testFiles/parallelograms.txt >> "compare/alex.txt"

./oliver testFiles/squares.txt >> "compare/oliver.txt"
./oliver testFiles/rectangles.txt >> "compare/oliver.txt"
./oliver testFiles/trapezoids.txt >> "compare/oliver.txt"
./oliver testFiles/rhombus.txt >> "compare/oliver.txt"
./oliver testFiles/parallelograms.txt >> "compare/oliver.txt"

for i in `seq 1 11500`;
do
    ./main < "compare/coords/$i.txt" >> "compare/alex.txt"
done  

for i in `seq 1 11500`;
do
    ./oliver "compare/coords/$i.txt" >> "compare/oliver.txt"
done 










