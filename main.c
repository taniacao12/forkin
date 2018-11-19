#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int main(){
  printf("START FORKING!\n");
  pid_t childA, childB;
  srand(time(NULL));
  printf("parent pid: %d\n", getppid());
  childA = fork();
  if (childA)
    childB = fork();
  if (childA == 0 || childB == 0) {
    printf("child pid : %d\n", getpid());
    int num = sleep(rand() % 15 + 5);
    printf("Child %d slept for %d seconds", getpid(), num);
  }

  int status, child;
  child = wait(&status);
  printf("parent %d knows child %d slept for %d seconds\n", getpid(), child, WEXITSTATUS(status));
  
  return 0;
}
