/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int t = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  t=1;
  exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1){
      while(t==0){
          printf("Turing was right!!\n");
          t = 0;
      }
  }
  return 0; //never reached
}