#!/bin/sh
mkdir -p week1
touch ./week1/file.txt
echo "Sergey Pasynkov" > ./week1/file.txt
mkdir -p week10
link ./week1/file.txt ./week10/_ex2.txt

INODE=$(stat -c '%i' ./week1/file.txt)

find -inum  $INODE >> ./week10/ex2.txt
find -inum $INODE -exec rm {} \; >> ./week10/ex2.txt
