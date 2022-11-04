#include "utils.h"
#include "chat.h"
int main()
{
    online_chat data;
    uint8_t source[4]={192,168,1,1};
    uint8_t dest[4]={10,21,1,2};
    uint16_t src_port=12;
    uint16_t dest_port=10054;
    int data_len=3;
    uint8_t *row=malloc(data_len);
    row[0]=1;
    row[1]=2;
    row[3]=3;
    set_IPV4(data.source,source);
    set_IPV4(data.dest,dest);
    data.source_port=src_port;
    data.dest_port=dest_port;
    data.data=row;
    data.data_len=data_len;
    time_t tmpcal_ptr;
    time(&tmpcal_ptr);
    data.time=*localtime(&tmpcal_ptr);
    send(data);
}