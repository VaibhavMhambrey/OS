arr=(8 9 2 3 5)
echo "Before Sort"
echo "${arr[@]}" 


arrlen=${#arr[@]}   #to get length of arr
for((i = 0; i < arrlen-1 ; i++))
do
min=$i
for((j = i + 1; j < arrlen; j++))
do
if [ ${arr[j]} -lt  ${arr[min]} ]
then
min=$j
fi
done

temp=${arr[i]}
arr[i]=${arr[min]}
arr[min]=$temp
done

echo "After Sort"
echo "${arr[@]}" 
