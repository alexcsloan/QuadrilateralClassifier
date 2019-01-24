./main < coords.txt > coordsOutput.txt
diff coordsOutput.txt coordsSolution.txt
error=$?
if [ $error -eq 0 ]
then
echo "test passed"
elif [ $error -eq 1 ]
then
echo "test failed"
else
echo "test didn't run properly"
fi