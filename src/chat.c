#include "chat.h"

void send(online_chat data)
{
    IPV4_header fake_header;
    for (int i = 0; i < 4; ++i)
    {
        fake_header.dest[i] = data.dest[i];
        fake_header.source[i] = data.source[i];
    }
    udp_sender(data.data, data.data_len, data.source_port, data.dest_port, fake_header);
}