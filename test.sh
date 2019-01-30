./main < txtFiles/err1.txt > txtFiles/err1Output.txt
diff txtFiles/err1Output.txt txtFiles/err1Sol.txt
error=$?
if [ $error -eq 0 ]
then
echo "err1 test passed!"
elif [ $error -eq 1 ]
then
echo "err1 test failed!"
exit 1
else
echo "err1 test didn't run properly!"
exit 1
fi

./main < txtFiles/err2.txt > txtFiles/err2Output.txt
diff txtFiles/err2Output.txt txtFiles/err2Sol.txt
error=$?
if [ $error -eq 0 ]
then
echo "err2 test passed!"
elif [ $error -eq 1 ]
then
echo "err2 test failed!"
exit 1
else
echo "err2 test didn't run properly!"
exit 1
fi

./main < txtFiles/err3.txt > txtFiles/err3Output.txt
diff txtFiles/err3Output.txt txtFiles/err3Sol.txt
error=$?
if [ $error -eq 0 ]
then
echo "err3 test passed!"
elif [ $error -eq 1 ]
then
echo "err3 test failed!"
exit 1
else
echo "err3 test didn't run properly!"
exit 1
fi

./main < txtFiles/err4.txt > txtFiles/err4Output.txt
diff txtFiles/err4Output.txt txtFiles/err4Sol.txt
error=$?
if [ $error -eq 0 ]
then
echo "err4 test passed!"
elif [ $error -eq 1 ]
then
echo "err4 test failed!"
exit 1
else
echo "err4 test didn't run properly!"
exit 1
fi

./main < txtFiles/err5.txt > txtFiles/err5Output.txt
diff txtFiles/err5Output.txt txtFiles/err5Sol.txt
error=$?
if [ $error -eq 0 ]
then
echo "err5 test passed!"
elif [ $error -eq 1 ]
then
echo "err5 test failed!"
exit 1
else
echo "err5 test didn't run properly!"
exit 1
fi

./main < txtFiles/err6.txt > txtFiles/err6Output.txt
diff txtFiles/err6Output.txt txtFiles/err6Sol.txt
error=$?
if [ $error -eq 0 ]
then
echo "err6 test passed!"
elif [ $error -eq 1 ]
then
echo "err6 test failed!"
exit 1
else
echo "err6 test didn't run properly!"
exit 1
fi

./main < txtFiles/err7.txt > txtFiles/err7Output.txt
diff txtFiles/err7Output.txt txtFiles/err7Sol.txt
error=$?
if [ $error -eq 0 ]
then
echo "err7 test passed!"
elif [ $error -eq 1 ]
then
echo "err7 test failed!"
exit 1
else
echo "err7 test didn't run properly!"
exit 1
fi

./main < txtFiles/err8.txt > txtFiles/err8Output.txt
diff txtFiles/err8Output.txt txtFiles/err8Sol.txt
error=$?
if [ $error -eq 0 ]
then
echo "err8 test passed!"
elif [ $error -eq 1 ]
then
echo "err8 test failed!"
exit 1
else
echo "err8 test didn't run properly!"
exit 1
fi

./main < txtFiles/err9.txt > txtFiles/err9Output.txt
diff txtFiles/err9Output.txt txtFiles/err9Sol.txt
error=$?
if [ $error -eq 0 ]
then
echo "err9 test passed!"
elif [ $error -eq 1 ]
then
echo "err9 test failed!"
exit 1
else
echo "err9 test didn't run properly!"
exit 1
fi

./main < txtFiles/err10.txt > txtFiles/err10Output.txt
diff txtFiles/err10Output.txt txtFiles/err10Sol.txt
error=$?
if [ $error -eq 0 ]
then
echo "err10 test passed!"
elif [ $error -eq 1 ]
then
echo "err10 test failed!"
exit 1
else
echo "err10 test didn't run properly!"
exit 1
fi

./main < txtFiles/err11.txt > txtFiles/err11Output.txt
diff txtFiles/err11Output.txt txtFiles/err11Sol.txt
error=$?
if [ $error -eq 0 ]
then
echo "err11 test passed!"
elif [ $error -eq 1 ]
then
echo "err11 test failed!"
exit 1
else
echo "err11 test didn't run properly!"
exit 1
fi

./main < txtFiles/err12.txt > txtFiles/err12Output.txt
diff txtFiles/err12Output.txt txtFiles/err12Sol.txt
error=$?
if [ $error -eq 0 ]
then
echo "err12 test passed!"
elif [ $error -eq 1 ]
then
echo "err12 test failed!"
exit 1
else
echo "err12 test didn't run properly!"
exit 1
fi

./main < txtFiles/err13.txt > txtFiles/err13Output.txt
diff txtFiles/err13Output.txt txtFiles/err13Sol.txt
error=$?
if [ $error -eq 0 ]
then
echo "err13 test passed!"
elif [ $error -eq 1 ]
then
echo "err13 test failed!"
exit 1
else
echo "err13 test didn't run properly!"
exit 1
fi

./main < txtFiles/err14.txt > txtFiles/err14Output.txt
diff txtFiles/err14Output.txt txtFiles/err14Sol.txt
error=$?
if [ $error -eq 0 ]
then
echo "err14 test passed!"
elif [ $error -eq 1 ]
then
echo "err14 test failed!"
exit 1
else
echo "err14 test didn't run properly!"
exit 1
fi

./main < txtFiles/err15.txt > txtFiles/err15Output.txt
diff txtFiles/err15Output.txt txtFiles/err15Sol.txt
error=$?
if [ $error -eq 0 ]
then
echo "err15 test passed!"
elif [ $error -eq 1 ]
then
echo "err15 test failed!"
exit 1
else
echo "err15 test didn't run properly!"
exit 1
fi

./main < txtFiles/kite.txt > txtFiles/kiteOutput.txt
diff txtFiles/kiteOutput.txt txtFiles/kiteSol.txt
error=$?
if [ $error -eq 0 ]
then
echo "kite test passed!"
elif [ $error -eq 1 ]
then
echo "kite test failed!"
exit 1
else
echo "kite test didn't run properly!"
exit 1
fi

./main < txtFiles/parallelogram.txt > txtFiles/parallelogramOutput.txt
diff txtFiles/parallelogramOutput.txt txtFiles/parallelogramSol.txt
error=$?
if [ $error -eq 0 ]
then
echo "parallelogram test passed!"
elif [ $error -eq 1 ]
then
echo "parallelogram test failed!"
exit 1
else
echo "parallelogram test didn't run properly!"
exit 1
fi

./main < txtFiles/quadrilateral.txt > txtFiles/quadrilateralOutput.txt
diff txtFiles/quadrilateralOutput.txt txtFiles/quadrilateralSol.txt
error=$?
if [ $error -eq 0 ]
then
echo "quadrilateral test passed!"
elif [ $error -eq 1 ]
then
echo "quadrilateral test failed!"
exit 1
else
echo "quadrilateral test didn't run properly!"
exit 1
fi

./main < txtFiles/rectangle.txt > txtFiles/rectangleOutput.txt
diff txtFiles/rectangleOutput.txt txtFiles/rectangleSol.txt
error=$?
if [ $error -eq 0 ]
then
echo "rectangle test passed!"
elif [ $error -eq 1 ]
then
echo "rectangle test failed!"
exit 1
else
echo "rectangle test didn't run properly!"
exit 1
fi

./main < txtFiles/rhombus.txt > txtFiles/rhombusOutput.txt
diff txtFiles/rhombusOutput.txt txtFiles/rhombusSol.txt
error=$?
if [ $error -eq 0 ]
then
echo "rhombus test passed!"
elif [ $error -eq 1 ]
then
echo "rhombus test failed!"
exit 1
else
echo "rhombus test didn't run properly!"
exit 1
fi

./main < txtFiles/square.txt > txtFiles/squareOutput.txt
diff txtFiles/squareOutput.txt txtFiles/squareSol.txt
error=$?
if [ $error -eq 0 ]
then
echo "square test passed!"
elif [ $error -eq 1 ]
then
echo "square test failed!"
exit 1
else
echo "square test didn't run properly!"
exit 1
fi

./main < txtFiles/trapezoid.txt > txtFiles/trapezoidOutput.txt
diff txtFiles/trapezoidOutput.txt txtFiles/trapezoidSol.txt
error=$?
if [ $error -eq 0 ]
then
echo "trapezoid test passed!"
echo "ALL TESTS PASSED"
elif [ $error -eq 1 ]
then
echo "trapezoid test failed!"
exit 1
else
echo "trapezoid test didn't run properly!"
exit 1
fi