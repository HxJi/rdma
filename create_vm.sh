#!bin/bash

# copy the same ubuntu image
# for i in {2..8}
# do
#     mkdir /var/lib/libvirt/images/guest$i
#     cp /var/lib/libvirt/images/guest1/*.img /var/lib/libvirt/images/guest$i/

# done

# create VMs
# for i in {2..8}
# do
#     virt-install --connect qemu:///system --ram 512 -n guest$i --os-type=linux \
#     --disk path=/var/lib/libvirt/images/guest$i/xenial-server-cloudimg-amd64-disk1.img,device=disk,bus=virtio,format=qcow2,size=5 \
#     --vcpus=1 --graphics none --import
# done

# bind cpu
# for i in {1..8}
# do
#      virsh vcpupin guest$i 0 $i
# done

# shutdown vms
for i in {1..8}
do
    virsh shutdown guest$i
done