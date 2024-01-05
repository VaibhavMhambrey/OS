echo "give no a"
read a
c=$(($a % 4))
if [ $c -eq 0 ]
then
echo "$a is leap year"
else 
echo -n "$a is not a leap year"
fi
echo ""
