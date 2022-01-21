#!bin/bash

sudo modprobe -r rdma_krping &&
sudo dmesg -c &&
sudo make clean