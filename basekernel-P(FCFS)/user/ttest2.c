#include "library/threads.h"
#include "library/string.h"


void Numbers(void *vargp)
{
    for(int i=1;i<10;i++){
        printf("%d\n",i);
        thread_sleep(1200);
    }
}
void Alphabets(void *vargp)
{
    for(int i=1;i<10;i++){
        printf("%c\n",(64+i));
        thread_sleep(1000);
    }
}

void main(){
    create_thread(Numbers,(void *)0,1);
    create_thread(Alphabets,(void *)0,1);
    process_join();
}