echo "give no a"
read a
c=$(($a % 2))
if [ $c -eq 0 ]
then
echo "$a is even"
else 
echo -n "$a is odd"
fi
echo ""
