#include "library/threads.h"
#include "library/user-io.h"
#include "library/string.h"

#define multimediaDuration 10		//10 seconds length
int timeElapsed = 0;
int isPaused=0;

void audioPlayer(){
	int audioTimeElapsed = 0;
	while(audioTimeElapsed<=multimediaDuration){
		if(!isPaused){
			printf("     Audio: %dsec\n",audioTimeElapsed );
			audioTimeElapsed++;
			thread_sleep(1000);		//Delay for 1sec
		}
		syscall_process_yield();
	}
	return;
}
void videoPlayer(){
	int videoTimeElapsed = 0;
	while(videoTimeElapsed<=multimediaDuration){
		if(!isPaused){
			printf("     Video: %dsec\n",videoTimeElapsed );
			videoTimeElapsed++;
			thread_sleep(1000);		//Delay for 1sec
		}
		syscall_process_yield();
	}
	return;
}
void multimediaPlayer(){
	while(timeElapsed<=multimediaDuration){
		if(!isPaused){
			timeElapsed++;
			thread_sleep(1000);		//Delay for 1sec
		}
		syscall_process_yield();	
	}
	return;
}

void main(){
	printf("Playing Multimedia file.\nDuration: 10sec\nPress P key to pause\n\n");
    create_thread(videoPlayer,(void *)0,1);
    create_thread(audioPlayer,(void *)0,1);
    create_thread(multimediaPlayer,(void *)0,1);
    char keyPress = 0;
	
	while(timeElapsed<=multimediaDuration){
		keyPress='c';
		keyPress = syscall_getchar_nonblock();
		if(keyPress=='p'||keyPress=='P'){
			if(isPaused){
				isPaused=0;
				printf("Resuming...\n");
				//Thread run for audio player, video player and multimedia player (@YJ)
			}else{
				isPaused=1;
				printf("Paused...\n");
				//Thread sleep for audio player, video player and multimedia player (@YJ)
			}	
		}
		
	}
    process_join();
	printf("End of File\n");
	syscall_process_exit(0);
}