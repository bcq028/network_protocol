#include "util.test.h"

int main(){
    //test time 
    time_t tmpcal_ptr;
    time(&tmpcal_ptr);
    struct tm time;
    time = *localtime(&tmpcal_ptr);
	printf("after gmtime, the time is:%d:%d:%d\n",\
     time.tm_hour, time.tm_min, time.tm_sec);
}