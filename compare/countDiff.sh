#!/bin/bash
quadrilateral=0
parallelogram=0
square=0
trapezoid=0
kite=0
rhombus=0
rectangle=0
error1=0
error2=0
error3=0
error4=0

FILE=alex.txt
while read LINE; do
        if [ "$LINE" == 'quadrilateral' ]
    then
    let quadrilateral++
        elif [ "$LINE" == 'parallelogram' ]
    then
    let parallelogram++
        elif [ "$LINE" == 'square' ]
    then
    let square++
        elif [ "$LINE" == 'trapezoid' ]
    then
    let trapezoid++
        elif [ "$LINE" == 'kite' ]
    then
    let kite++
        elif [ "$LINE" == 'rhombus' ]
    then
    let rhombus++
        elif [ "$LINE" == 'rectangle' ]
    then
    let rectangle++
        elif [ "$LINE" == 'error 1' ]
    then
    let error1++
        elif [ "$LINE" == 'error 2' ]
    then
    let error2++
        elif [ "$LINE" == 'error 3' ]
    then
    let error3++
        elif [ "$LINE" == 'error 4' ]
    then
    let error4++
    fi
done < $FILE


quadrilateral2=0
parallelogram2=0
square2=0
trapezoid2=0
kite2=0
rhombus2=0
rectangle2=0
error12=0
error22=0
error32=0
error42=0

FILE=oliver.txt
while read LINE; do
        if [ "$LINE" == 'quadrilateral' ]
    then
    let quadrilateral2++
        elif [ "$LINE" == 'parallelogram' ]
    then
    let parallelogram2++
        elif [ "$LINE" == 'square' ]
    then
    let square2++
        elif [ "$LINE" == 'trapezoid' ]
    then
    let trapezoid2++
        elif [ "$LINE" == 'kite' ]
    then
    let kite2++
        elif [ "$LINE" == 'rhombus' ]
    then
    let rhombus2++
        elif [ "$LINE" == 'rectangle' ]
    then
    let rectangle2++
        elif [ "$LINE" == 'error 1' ]
    then
    let error12++
        elif [ "$LINE" == 'error 2' ]
    then
    let error22++
        elif [ "$LINE" == 'error 3' ]
    then
    let error32++
        elif [ "$LINE" == 'error 4' ]
    then
    let error42++
    fi
done < $FILE

echo "quadrilateral:" >> "results.txt"
echo "     alex: $quadrilateral" >> "results.txt"
echo "     oliver: $quadrilateral2" >> "results.txt"
echo "parallelogram:" >> "results.txt"
echo "     alex: $parallelogram" >> "results.txt" 
echo "     oliver: $parallelogram2" >> "results.txt"
echo "square:" >> "results.txt"
echo "     alex: $square" >> "results.txt"
echo "     oliver: $square2" >> "results.txt"
echo "trapezoid:" >> "results.txt"
echo "     alex: $trapezoid" >> "results.txt"
echo "     oliver: $trapezoid2" >> "results.txt"
echo "kite:" >> "results.txt"
echo "     alex: $kite" >> "results.txt" 
echo "     oliver: $kite2" >> "results.txt"
echo "rhombus:" >> "results.txt"
echo "     alex: $rhombus" >> "results.txt" 
echo "     oliver: $rhombus2" >> "results.txt"
echo "rectangle:" >> "results.txt"
echo "     alex: $rectangle" >> "results.txt" 
echo "     oliver: $rectangle2" >> "results.txt"
echo "error 1:" >> "results.txt"
echo "     alex: $error1" >> "results.txt" 
echo "     oliver: $error12" >> "results.txt"
echo "error 2:" >> "results.txt"
echo "     alex: $error2" >> "results.txt" 
echo "     oliver: $error22" >> "results.txt"
echo "error 3:" >> "results.txt"
echo "     alex: $error3" >> "results.txt" 
echo "     oliver: $error32" >> "results.txt"
echo "error 4:" >> "results.txt"
echo "     alex: $error4" >> "results.txt" 
echo "     oliver: $error42" >> "results.txt"





