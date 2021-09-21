touch file.txt
echo 1 >> file.txt

while true;
do
    next_num=$(($(grep -Eo '^[0-9]+$' file.txt | tail -1)+1))
    echo "$next_num" >> file.txt
done