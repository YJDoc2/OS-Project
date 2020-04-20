#include "library/syscalls.h"

#ifndef THREADS_CUSTOM
#define THREADS_CUSTOM
int create_thread(void *fn,void *arg);
int process_join();

inline static void thread_sleep(int ms){
    syscall_process_sleep(ms);
}

#endif