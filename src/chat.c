#include "chat.h"

uint8_t* send(online_chat data)
{
    IPV4_header fake_header;
    for (int i = 0; i < 4; ++i)
    {
        fake_header.dest[i] = data.dest[i];
        fake_header.source[i] = data.source[i];
    }
    printf("应用层发送数据: %d位\n",data.data_len);
    printf_byte(data.data,data.data_len);
    return udp_sender(data.data, data.data_len, data.source_port, data.dest_port, fake_header);
}