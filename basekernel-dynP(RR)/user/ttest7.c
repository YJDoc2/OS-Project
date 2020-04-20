#include "library/threads.h"
#include "library/syscalls.h"
#include "library/string.h"


void task_1(void *vargp)
{
    for(int i=0;i<10;i++){
        for(int k=0;k<5;++k){
            float f = -32000;
            for(;f<32000;f+=0.1){

            }
        }
        printf("In Task 1 ... Calculating...\n");
        syscall_process_yield();
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<3;++j){
            printf("In Task 1 ... Interactive ...\n");
        }
        syscall_process_yield();
    }
}
void task_2(void *vargp)
{
    for(int i=0;i<5;i++){
        for(int j=0;j<3;++j){
            printf("In Task 2 ... Interactive ...\n");
        }
        syscall_process_yield();
    }
    for(int i=0;i<10;i++){
        for(int k=0;k<5;++k){
            float f = -32000;
            for(;f<32000;f+=0.1){

            }
        }
        printf("In Task 2 ... Calculating ...\n");
        syscall_process_yield();
    }
}

void main(){
    create_thread(task_1,(void *)0);
    create_thread(task_2,(void *)0);
    process_join();
}
