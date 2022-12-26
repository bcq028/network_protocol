#include "utils.h"

uint16_t add(uint16_t b1,uint16_t b2){
    long long int t=b1+b2;
    uint16_t ret=t%0x10000;
    int carry=t>>16;
    if(carry>0){
        return add(ret,carry);
    }else{
        return ret;
    }
}

uint16_t transfer(uint8_t b1,uint8_t b2){
    return (b1<<8)+b2;
}

/**
 * 将双字节数据转化为字节数组
*/
void transfer_back(uint16_t db,uint8_t* ret){
    ret[0]=db>>8;
    ret[1]=db%0b100000000;
}


uint16_t get_sum_of_buffer(uint16_t *buffer,int len){
    uint16_t ret=0;
    for(int i=0;i<len;i++){
        ret=add(ret,buffer[i]);
    }
    return ret;
}

uint32_t flaten_uint8_tarr_to_fouruint8_t(uint8_t* barr){
    return (barr[0]<<24)+(barr[1]<<16)+(barr[2]<<8)+barr[3];
}

void set_IPV4(IPV4 dest,uint8_t* addr){
    for(int i=0;i<4;++i){
        dest[i]=addr[i];
    }
}

void set_port(uint8_t*dest,uint8_t*port){
    dest[0]=port[0];
    dest[1]=port[1];
}

/**
 * 拼接两个字符数组的数据
*/
uint8_t* concat(uint8_t* a,int a_len,uint8_t* b,int b_len){
    uint8_t* ret=malloc(a_len+b_len);
    memcpy(ret,a,a_len);
    memcpy(ret+a_len,b,b_len);
    return ret;
}

uint8_t* insert(uint8_t* buffer,int buffer_size,int index,uint8_t elem){
    if(index<0||index>buffer_size){
        printf("error in insert:target index out of bound");
    }
    uint8_t* ret=malloc(buffer_size+1);
    for(int i=buffer_size;i>=0;i--){
        ret[i]=i>index?buffer[i-1]:buffer[i];
    }
    ret[index]=elem;
    return ret;
}

void printf_byte(uint8_t * start,int len){
    for(int i=0;i<len;++i){
        printf("%d\n",start[i]);
    }
}