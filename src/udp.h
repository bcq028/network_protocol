#ifndef _UDP_H_
#define _UDP_H_

#include "utils.h"
#include "ip.h"

typedef struct
{
    uint8_t source[2];
    uint8_t dest[2];
    uint8_t len[2];
    uint8_t check[2];
} udp_header;


typedef struct
{
    udp_header header;
    uint8_t *data;
} udp_packet;

uint16_t get_check_code(udp_header header, IPV4_header fake, uint8_t *udp_data);

/**
 * 将应用层报文封装为udp数据报
*/
uint8_t* udp_sender(uint8_t *data, uint16_t data_len, uint16_t source, uint16_t dest,IPV4_header fake);

#endif
