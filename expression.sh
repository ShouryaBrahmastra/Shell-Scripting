echo "Enter the value of x"
read x
s=0.0
i=1
n=`echo "$i<=$x" | bc`
while [ $n -eq 1 ]
do 
  c=`echo "l($i)/l(10)" | bc -l`
  s=`echo "$s+$c" | bc`
  i=`echo "$i+1" | bc`
  n=`echo "$i<=$x" | bc`
done
echo $s