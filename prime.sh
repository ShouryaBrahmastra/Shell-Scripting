echo "Enter a number"
read num
for((i=2; i<=$num/2; i++))
do
  answer=$(( num%i ))
  if [ $answer -eq 0 ]
  then
  	echo "Not prime"
  	exit 0
  fi
done
echo "Is prime"