#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static void sighandler(int signo){
  if (signo == SIGINT){
    printf("recieved SIGINT\n");
    exit(0);
  }
  if (signo == SIGUSR1){
    printf("Parent process #: %d\n", getppid());
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while (1){
    printf("Hi! My PID is: %d\n", getpid());
    sleep(1);
  }
}
