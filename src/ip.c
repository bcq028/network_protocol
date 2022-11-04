#include "ip.h"


uint16_t* transfer_header_into_doubleuint8_t(ip_header header){
    uint16_t *buffer=malloc(sizeof(header));
    memcpy(buffer,&header,sizeof(header));
    return buffer;
}


uint16_t get_ip_check_code(ip_header header){
    uint16_t * buffer=transfer_header_into_doubleuint8_t(header);
    int len=sizeof(header)/2; // 两个字节为一组
    uint16_t ret=0;
    for(int i=0;i<len;++i){
        ret=add(ret,buffer[i]);
    }
    return ~ret;
}

void ip_sender(uint8_t *buffer,int len,uint32_t source,uint32_t dest){
    ip_header header;
    header.version=4;
    header.IHL=5;
    header.DSCP=0;
    header.ECN=0;
    header.Total_length=4*header.IHL+len; // IHL单位为4B 
    header.Identification=0;
    header.Flags=0;
    header.Fragment_offset=0;
    header.TTL=128;
    header.protocol=17;  //UDP对应的协议字段值是17，TCP对应6
    header.header_checksum=0; // ip检验头先填充0
    header.IP_source_addr=source;
    header.IP_dest_addr=dest;
    //计算IP检验头
    header.header_checksum=get_ip_check_code(header);
    //TODO 将ip数据报交给数据链路层处理
    // frame_sender(buffer,len);
}