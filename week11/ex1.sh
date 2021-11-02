#!/bin/sh
dd if=/dev/zero of=lofs.img bs=1M count=50
sudo losetup -fP lofs.img
losetup -a
sudo mkfs.ext4 ./lofs.img
mkdir lofsdisk
sudo mount -o loop /dev/loop33 ./lofsdisk/
df -hP lofsdisk