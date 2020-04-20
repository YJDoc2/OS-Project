#include "library/threads.h"
#include "library/string.h"

int check =0;

void test_fn(){
    // for(int i =0;i<5;++i){
    //     printf("In test Fn  %d\n",k);
    // }
    printf("IN TEST check = %d\n",check);
    check++;
    thread_sleep(1000);
    printf("IN TEST Modified check = %d\n",check);
    //syscall_process_exit(0);
}

void main(){

    printf("In Main\n");
    printf("check = %d\n",check);
    create_thread(test_fn,(void *)0);
    create_thread(test_fn,(void *)0);
    process_join();
    printf("check = %d\n",check);
    printf("main = %x\n",main);
    printf("test fn = %x\n",test_fn);
    

}