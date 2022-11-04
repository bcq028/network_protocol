#ifndef _IP_H_
#define _IP_H_

#include "utils.h"
#include "ppp.h"

typedef struct 
{
    unsigned version:4;
    unsigned IHL:4;
    unsigned DSCP:6;
    unsigned ECN:2;
    unsigned Total_length:16;
    unsigned Identification:16;
    unsigned Flags:3;
    unsigned Fragment_offset:13;
    unsigned TTL:8;
    unsigned protocol:8;
    unsigned header_checksum:16;
    unsigned IP_source_addr:32;
    unsigned IP_dest_addr:32;
} ip_header;



typedef struct
{
    ip_header header;
    uint8_t *data;
    int data_len;
} ip_packet;

uint16_t get_ip_check_code(ip_header header);

/**
 * 将udp数据报封装为ip数据报
*/
void ip_sender(uint8_t *buffer,int len,uint32_t source,uint32_t dest);


#endif
 