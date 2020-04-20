#include "library/threads.h"
#include "library/syscalls.h"
#include "library/string.h"


void Numbers(void *vargp)
{
    for(int i=1;i<10;i++){
        float f = -32000;
        syscall_process_yield();
        printf("%d\n",i);
    }
}
void Alphabets(void *vargp)
{
    for(int i=1;i<10;i++){
        float f = -32000;
        syscall_process_yield();
        printf("%c\n",(64+i));
    }
}

void main(){
    create_thread(Numbers,(void *)0);
    create_thread(Alphabets,(void *)0);
    process_join();
}
