#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t *buffer(){
    uint8_t* ret=malloc(4);
    ret[2]=0xff;
    return ret;
}

int main(){
    uint8_t *t=buffer();
    for(int i=0;i<30;++i){
        if(t[i]==0xff){
            
        }else{
            printf("%x\n",t[i]);
        }
    }
}