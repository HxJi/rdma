
#!bin/bash

make && sudo make install && sudo modprobe rdma_krping &&
echo "server,addr=192.168.101.14,port=20886,debug" >/proc/krping