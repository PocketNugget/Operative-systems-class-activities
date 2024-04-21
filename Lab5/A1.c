#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int hola = 0; 
void sig_handler(int signum)
{
  printf("esperando 3 segundos\n");
  sleep(3);  // Delay for 1 second
  hola++;
  if(hola>3){
    _exit (0);
  }
}
 
int main()
{ 
  signal(SIGINT,sig_handler); // Register signal handler

  for(int i=1;;i++)
  {
    printf("%d\n",getpid());
    sleep(1);  // Delay for 1 second
  }
  return 0;
}

