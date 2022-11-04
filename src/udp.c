#include "udp.h"

uint16_t get_check_code(udp_header header,IPV4_header fake,uint8_t* udp_data){
     uint16_t sum=0;
    //伪首部相加
    sum=add(sum,transfer(fake.source[0],fake.source[1]));
    sum=add(sum,transfer(fake.source[2],fake.source[3]));
    sum=add(sum,transfer(fake.dest[0],fake.dest[1]));
    sum=add(sum,transfer(fake.dest[2],fake.dest[3]));
    sum=add(sum,transfer(0,17));
    sum=add(sum,15);
    //udp首部相加
    sum=add(sum,transfer(header.source[0],header.source[1]));
    sum=add(sum,transfer(header.dest[0],header.dest[1]));
    sum=add(sum,transfer(header.len[0],header.len[1]));
    // udp数据相加
    for(int i=0;i<transfer(header.len[0],header.len[1]);i++){
        sum=add(sum,udp_data[i]);
    }
    return ~sum;
}


// 应用层调用此方法将数据转化为udp数据报
void udp_sender(uint8_t*data,uint16_t data_len,uint16_t source, uint16_t dest,IPV4_header fake){
    udp_header header;
    //全0填充检验和字段与数据部分
    header.check[0]=0;
    header.check[1]=0;
    bool flag=false;
    if(data_len%2!=0){
        data[data_len++]=0;
        flag=true;
    }
    // 设置udp头部
    transfer_back(data_len,header.len);
    transfer_back(source,header.source);
    transfer_back(dest,header.dest);
    transfer_back(get_check_code(header,fake,data),header.check);
    if(flag) transfer_back(data_len-1,header.len);
    //原始数据+udp头
    uint8_t *udp_data=concat((uint8_t*)&header,sizeof(header),data,data_len);
    //发送ip包
    ip_sender(udp_data,data_len+sizeof(header),flaten_uint8_tarr_to_fouruint8_t(fake.source),flaten_uint8_tarr_to_fouruint8_t(fake.dest));
}

