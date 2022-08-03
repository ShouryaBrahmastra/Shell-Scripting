echo "Enter two numbers : "
echo "First number: "
read num1
echo "Second number: "
read num2
echo "Enter the choice"
echo "1.> Addition"
echo "2.> Subtraction"
echo "3.> Multiply"
echo "4.> Divide"
echo "Enter the choice: "
read var

case $var in
 1)     echo $(($num1+$num2))
 	exit 0 
 	;;
 2)     echo $(($num1-$num2))
 	exit 0 
 	;; 	
 3)     echo $(($num1*$num2))
 	exit 0 
 	;; 	
 4)     echo $(($num1/$num2))
 	exit 0 
 	;; 	
 *)     echo "Wrong choice"
 	exit 0 
 	;; 	
esac 