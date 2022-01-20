#include "utils.h"
#include "server.h"
#include "client.h"
/* develop based on krping code 
kernel version: 5.4.0
"ping/pong loop design for KSM" 
KSM(client) sends source rkey/addr/len
SmartNIC (server) recieves source rkey/addr/len
SmartNIC (server) reads ping data (pages) from source
SmartNIC (server) compares the pages and get result
SmartNIC (server) sends "go ahead" on rdma read completion
KSM(client) sends sink rkey/addr/len
SmartNIC (server) recieves sink rkey/addr/len
SmartNIC (server) writes pong data (comparsion result) to sink
SmartNIC (server) sends "go ahead" on rdma read completion
<repeat loop>
*/



