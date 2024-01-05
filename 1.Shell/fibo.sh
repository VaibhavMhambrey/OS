echo "Give number"
read n
echo ""
a=0
b=1
for (( i=1;i<=n;i++ ))
do
echo -n "$a"
fibo=$((a + b))
a=$b
b=$fibo
echo ""
done
echo ""
