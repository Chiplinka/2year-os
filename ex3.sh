#!/bin/sh
touch _ex3.txt
touch ex3.txt
echo "Sergey Pasynkov Ex3" > _ex3.txt

chmod 664 _ex3.txt
ls -l _ex3.txt >> ex3.txt

chmod u=rwx,o=rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt

chmod g=u _ex3.txt
ls -l _ex3.txt >> ex3.txt

echo '660: Makes the file avaliable for read\write for user and removes all permissions for other users.' >> ex3.txt
echo '775: Gives all permissions for user and read/execute access for other users.' >> ex3.txt
echo '777: Gives all permissions of that file for everyone.' >> ex3.txt

