#!bin/bash

make && sudo make install && sudo modprobe rdma_krping debug=1 &&
echo "client,addr=192.168.101.14,port=20886,count=2,validate,verbose" >/proc/krping
# while :
#       do 
#         # echo "Server run $i times"
#         echo "client,addr=192.168.101.14,port=20886,count=2,validate,verbose" >/proc/krping
#     done

