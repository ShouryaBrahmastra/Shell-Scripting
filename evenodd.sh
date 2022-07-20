echo "Enter a number:-"
read number
check=$((number%2))
if [ $check -eq 0 ]
then
echo "It is even"
else
echo "It is odd"
fi
