#include <stdio.h>
#include <stdlib.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <inttypes.h>

#include "setup_ib.h"

#ifndef SETUP_IB_H_
#define SETUP_IB_H_

#include <rdma/ib_verbs.h>
#include <rdma/mr_pool.h>

// define IB resources
struct resources{
    struct ib_device_attr device_attr;
    struct ib_port_attr port_attr;
    struct ib_context *ib_ctx;
    struct ib_pd *pd;
    struct ib_cq *cq;
    struct ib_qp *qp;
    struct ib_mr *mr;

    char *ib_buf;       // memory buffer pointer
    size_t ib_buf_size;
};

int setup_ib();
void close_ib_connections();

#endif

// keep server and client codes both in kernel space
struct ConfigInfo{
    bool is_server;     // server or client
    char *server_name;
    char *server_port;
    int msg_size;       // default 4096
    int num_concurr_msgs;
}

int main(int argc, char *argv[]){
    int ret = 0;
    // initialize the configuration parameters
    struct ConfigInfo config_info;
    if(argc == 4){
        config_info.is_server = true;
        config_info.msg_size = 4096;
        config_info.num_concurr_msgs = 2;
        config_info.server_name = argv[1];
        config_info.server_port = argv[2];
    }else if(argc == 3){
        config_info.is_server = false;
        config_info.msg_size = 4096;
        config_info.num_concurr_msgs = 2;
        config_info.server_name = argv[1];
        config_info.server_port = argv[2];
    }else{
        pr_info("server: server ip, server port, 1; client: server ip, server port.\n");
        return 0;
    }

    // setup IB connections
    ret = setup_ib();

}


#include <rdma/ib_verbs.h>
#include <rdma/mr_pool.h>

#include "setup_ib.h"

// ksm code in kernel mode, client in user space


int setup_ib(){
    int ret = 0;
    struct ib_device **device_list = NULL;

}

