#include "library/threads.h"
#include "library/syscalls.h"
#include "library/string.h"


void calc_tack(void *vargp)
{
    for(int i=0;i<15;i++){
        for(int k=0;k<5;++k){
            float f = -32000;
            for(;f<32000;f+=0.1){

            }
        }
        printf("In Calculating task...\n");
        syscall_process_yield();        
    }
}
void interactive_task(void *vargp)
{
    for(int i=0;i<10;i++){
        for(int j=0;j<3;++j){
            printf("In interactive task...\n");
        }
        syscall_process_yield();
    }
}

void main(){
    create_thread(calc_tack,(void *)0);
    create_thread(interactive_task,(void *)0);
    process_join();
}
