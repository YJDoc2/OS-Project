#include "library/syscalls.h"
#include "library/threads.h"
#include "library/user-io.h"
#include "library/string.h"

float arrF[1000];
float mul =1;
long int arrI[1000];
long int sum =0;

void set_and_sum(void *arg){

    int lim = (int)arg;
    float f = lim;
    for(float i=0;i<lim;i+=0.2){
        //arrI[i] = i+1;
    }
    printf("Int Array Set ...\n");
    for(float i=0;i<lim;i+=0.2){
        //thread_sleep(1);
        //sum += arrI[i];
    }

    printf("Sum Is : %d ...\n",sum);

}

void set_and_mul(void *arg){
    int lim = (int)arg;
    float f = lim;
    for(float i=0;i<lim;i+=0.2){
        //arrF[i] = i+1;
    }
    printf("Float Array Set ...\n");
    for(float i=0;i<lim;i+=0.2){
        //thread_sleep(1);
        //mul *= arrF[i];
    }

    printf("Multiplication Is : %f ...\n",mul);

}

void main(){
    unsigned int time1,time2;
    printf("Startig Non-Threading...\n");
    syscall_system_time(&time1);
    set_and_sum((void*)3200000);
    set_and_mul((void*)3200000);
    syscall_system_time(&time2);
    printf("Time Elapsed = %d\n",time2-time1);
    printf("\nStartig Threading...\n\n");
    syscall_system_time(&time1);
    create_thread(set_and_sum,(void*)3200000);
    create_thread(set_and_mul,(void*)3200000);
    process_join();
    syscall_system_time(&time2);
    printf("Time Elapsed = %d\n",time2-time1);
}