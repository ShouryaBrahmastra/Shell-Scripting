echo "Enter your name:-"
read name
echo "Enter length of the rectangle:-"
read length
echo "Enter breadth of the rectangle:-"
read breadth
area=$(($length*$breadth))
perimeter=$((2*$(($length+$breadth))))
echo "Your name is:-"$name
echo "Area of the rectangle is:-"$area
echo "Perimeter of the rectangle is:-"$perimeter
