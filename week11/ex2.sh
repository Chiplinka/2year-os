#![/bin/sh]

sudo chmod 777  lofsdisk
sudo echo 'Sergey' > lofsdisk/file1.txt
sudo echo 'Pasynkov' > lofsdisk/file2.txt

gcc ex2.c -o ex2.out
sudo cp ex2.out lofsdisk
sudo mkdir lofsdisk/bin

sudo cp /bin/bash lofsdisk/bin
sudo cp /bin/cat lofsdisk/bin
sudo cp /bin/echo lofsdisk/bin
sudo cp /bin/ls lofsdisk/bin

sudo mkdir lofsdisk/usr
sudo mkdir lofsdisk/usr/lib
sudo mkdir lofsdisk/usr/lib64

sudo cp /usr/lib/libreadline.so.8 lofsdisk/usr/lib
sudo cp /usr/lib/libdl.so.2 lofsdisk/usr/lib
sudo cp /usr/lib/libc.so.6 lofsdisk/usr/lib
sudo cp /usr/lib/libncursesw.so.6 lofsdisk/usr/lib
sudo cp /usr/lib64/ld-linux-x86-64.so.2 lofsdisk/usr/lib64 
sudo cp /usr/lib/libcap.so.2 lofsdisk/usr/lib

cd lofsdisk
sudo chroot . ./ex2.out > ../ex2.txt
./ex2.out >> ../ex2.txt