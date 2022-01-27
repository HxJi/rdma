#!bin/bash

make && sudo make install && sudo modprobe rdma_krping debug=1 &&

# while :
#       do 
#         # echo "Server run $i times"
#         echo "server,addr=192.168.101.14,port=20886,verbose,validate" >/proc/krping
#     done

# for i in {0..10}:
echo "server,addr=192.168.101.13,port=20886,verbose,validate,verbose" >/proc/krping