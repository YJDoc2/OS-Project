#include "library/syscalls.h"
#include "library/threads.h"

int create_thread(void *fn,void *arg,int pri){
    if(pri>5)pri =5;
    if(pri<-4)pri=-4;
    return syscall_create_thread(fn,arg,pri);
}

int process_join(){
   return syscall_process_join();
}
