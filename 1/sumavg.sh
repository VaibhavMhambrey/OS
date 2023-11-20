echo "Give number of items"
read n
add=0
avg=0
for (( i=1;i<=n;i++ ))
do
echo "give no"
read a
add=$(($add + a ))
done
avg=$(($add / $n))
echo "sum = $add"
echo ""
echo "avg = $avg"
