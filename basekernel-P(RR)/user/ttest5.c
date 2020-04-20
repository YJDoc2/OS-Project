#include "library/threads.h"
#include "library/syscalls.h"
#include "library/string.h"


void Numbers(void *vargp)
{
    for(int i=1;i<10;i++){
        float f = -32000;
        printf("%d\n",i);
        syscall_process_yield();
    }
}
void Alphabets(void *vargp)
{
    for(int i=1;i<10;i++){
        float f = -32000;
        printf("%c\n",(64+i));
        syscall_process_yield();
    }
}

void main(){
    create_thread(Numbers,(void *)0,1);
    create_thread(Alphabets,(void *)0,1);
    process_join();
}
