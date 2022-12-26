#ifndef _FRAME_H_
#define _FRAME_H_

#include "crc16.h"

typedef struct
{
    uint8_t SF;
    uint8_t A;
    uint8_t C;
    uint16_t protocol;
    uint8_t* data;
    uint16_t FCS;
    uint8_t EF;
} ppp_frame;

/**
 * 将ip数据报封装为以太帧,返回指针
 */
uint8_t * frame_sender(uint8_t *buffer, int len);


/**
 * 解析以太帧
*/
void frame_getter(uint8_t* buffer);

#endif