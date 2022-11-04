#ifndef _UTILS_H_
#define _UTILS_H_
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
typedef uint8_t IPV4[4];
typedef struct
{
    IPV4 source;
    IPV4 dest;
} IPV4_header;

uint16_t add(uint16_t b1, uint16_t b2);

/**
 * 将buffer区域的数据按2B为一组循环相加
 * @param buffer 指向数据缓冲区的首地址
 * @param len buffer的大小，单位为字节
*/
uint16_t get_sum_of_buffer(uint16_t *buffer,int len);

uint16_t transfer(uint8_t b1, uint8_t b2);


void transfer_back(uint16_t db, uint8_t *ret);

uint32_t flaten_uint8_tarr_to_fouruint8_t(uint8_t* barr);

void set_IPV4(IPV4 dest,uint8_t* addr);

void set_port(uint8_t*dest,uint8_t*port);

uint8_t* concat(uint8_t* a,int a_len,uint8_t* b,int b_len);

uint8_t* insert(uint8_t* buffer,int buffer_size,int index,uint8_t elem);
#endif
