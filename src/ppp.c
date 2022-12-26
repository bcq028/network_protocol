#include "ppp.h"
#define CRC8_POLYNOMIAL (0x31)

int _size_of_cur_buffer = 0;

uint8_t *insert_0x7E(uint8_t *buffer, int buffer_size)
{
    for (int i = 0; i < buffer_size; ++i)
    {
        if (buffer[i] == 0x7E)
        {
            _size_of_cur_buffer++;
            buffer[i] = 0x7D;
            buffer = insert(buffer, buffer_size, i + 1, 0x5E);
            return insert_0x7E(buffer, buffer_size + 1);
        }
    }
    return buffer;
}
uint8_t *insert_0x5D(uint8_t *buffer, int buffer_size)
{
    for (int i = 0; i < buffer_size; ++i)
    {
        if (buffer[i] == 0x7D && buffer[i + 1] != 0x5E)
        {
            _size_of_cur_buffer++;
            buffer = insert(buffer, buffer_size, i + 1, 0x5D);
            return insert_0x5D(buffer, buffer_size + 1);
        }
    }
    return buffer;
}

uint8_t *insert_0x7D(uint8_t *buffer, int buffer_size)
{
    for (int i = 0; i < buffer_size; ++i)
    {
        if (buffer[i] < 0x20)
        {
            _size_of_cur_buffer++;
            buffer = insert(buffer, buffer_size, i, 0x7D);
            buffer[i + 1] += 20;
            return insert_0x7D(buffer, buffer_size + 1);
        }
    }
    return buffer;
}

uint8_t *fill_byte(uint8_t *buffer, int buffer_size)
{
    _size_of_cur_buffer = buffer_size;
    buffer = insert_0x7E(buffer, _size_of_cur_buffer);
    buffer = insert_0x5D(buffer, _size_of_cur_buffer);
    buffer = insert_0x7D(buffer, _size_of_cur_buffer);
    return buffer;
}


uint8_t * frame_sender(uint8_t *buffer, int len)
{
    ppp_frame data;
    data.SF = 0x7e;
    data.A = 0xFF;
    data.C = 0x3;
    data.protocol = 0x0021; //表示数据是ip数据报
    data.data = fill_byte(buffer, len);
    data.FCS = crc_16(data.data, _size_of_cur_buffer);
    data.EF = 0x7e;
    uint8_t * ret=malloc(sizeof(data));
    memcpy(ret,&data,sizeof(data));
    return ret;
}

void frame_getter(uint8_t *buffer){
    ppp_frame data;
    for(int i=0;;i++){
        if(buffer[i]==0x7e){
           break;  
        }
    }
   data=*(ppp_frame*)buffer;
}