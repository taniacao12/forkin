#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

int main(){
  printf("START FORKING!\n");
  srand(time(NULL));
  printf("parent pid: %d\n", getppid());
  fork();
  while (getppid() != -1) {
    printf("parent pid: %d\n", getppid());
    printf("child pid: %d\n", getpid());
    sleep(rand() % 15 + 5);
  }
  
  return 0;
}
