#!/bin/bash

errorCounter=0

./main < testFiles/squares.txt > testFiles/squareOutput.txt
diff testFiles/squareOutput.txt testFiles/squareSol.txt
error=$?
if [ $error -eq 1 ]
then
errorCounter+=1
fi

./main < testFiles/rectangles.txt > testFiles/rectangleOutput.txt
diff testFiles/rectangleOutput.txt testFiles/rectangleSol.txt
error=$?
if [ $error -eq 1 ]
then
errorCounter+=1
fi

./main < testFiles/trapezoids.txt > testFiles/trapezoidOutput.txt
diff testFiles/trapezoidOutput.txt testFiles/trapezoidSol.txt
error=$?
if [ $error -eq 1 ]
then
errorCounter+=1
fi

./main < testFiles/rhombus.txt > testFiles/rhombusOutput.txt
diff testFiles/rhombusOutput.txt testFiles/rhombusSol.txt
error=$?
if [ $error -eq 1 ]
then
errorCounter+=1
fi

./main < testFiles/parallelograms.txt > testFiles/parallelogramOutput.txt
diff testFiles/parallelogramOutput.txt testFiles/parallelogramSol.txt
error=$?
if [ $error -eq 1 ]
then
errorCounter+=1
fi

for i in `seq 1 1000`;
do
    output="output"
    ./main < "testFiles/$i.txt" > "testFiles/$output$i.txt"
done  


if [ $errorCounter \> 0 ]
then
echo "ERROR"
exit 1
elif [ $errorCounter -eq 0 ]
then
echo "OK"
exit 0
fi

