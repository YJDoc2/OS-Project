#include "library/syscalls.h"
#include "library/threads.h"

int create_thread(void *fn,void *arg){
    return syscall_create_thread(fn,arg);
}

int process_join(){
   return syscall_process_join();
}
