#ifndef _CHAT_H_
#define _CHAT_H_

#include "utils.h"
#include "udp.h"

typedef struct 
{
    IPV4 source;
    IPV4 dest;
    uint16_t source_port;
    uint16_t dest_port;
    //用户数据
    uint8_t *data;
    //数据大小(uint8_t)
    int data_len;
    //发送时间 
    struct tm time;
} online_chat;

uint8_t* send(online_chat data);

#endif