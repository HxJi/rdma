#!bin/bash

make && sudo make install && sudo modprobe rdma_krping debug=0 &&
echo "client,addr=192.168.101.12,port=20886,count=5000" >/proc/krping
# while :
#       do 
#         # echo "Server run $i times"
#         echo "client,addr=192.168.101.14,port=20886,count=2,validate,verbose" >/proc/krping
#     done
