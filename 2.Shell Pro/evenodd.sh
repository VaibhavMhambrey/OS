echo "Give number"
read n
odd=0
even=0
while [ $n -gt 0 ]
do
dig=$(($n % 10))
check=$(($dig%2))
if [ $check -eq 0 ]
then
even=$(($even + 1))
else
odd=$(($odd + 1))
fi
n=$(($n/10))
done
echo "even=$even"
echo ""
echo "odd=$odd"
