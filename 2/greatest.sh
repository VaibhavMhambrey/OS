echo "give n value"
read n
i=1
max=0
echo -n "give numbers"
echo ""
for ((i=1;i<=n;i++))
do
read a
if [ $i -eq 1 ]
then
max=$a
else
if [ $a -gt $max ]
then 
max=$a
fi
fi
done
echo -n "max=$max"
echo ""
