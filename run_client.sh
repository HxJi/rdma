#!bin/bash

echo "client,addr=192.168.101.14,port=20886,count=2,validate,verbose" >/proc/krping &&
make && sudo make install && sudo modprobe rdma_krping debug=1