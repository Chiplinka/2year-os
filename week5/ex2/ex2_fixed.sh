touch my_file.txt
echo 1 >> my_file.txt

while true; do
if ln my_file.txt my_file.lock &> /dev/null;
then
line=`tail -1 my_file.lock`
echo $((line+1)) >> my_file.lock
rm my_file.lock
 fi
done