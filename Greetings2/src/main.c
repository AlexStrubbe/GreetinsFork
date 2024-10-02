#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{

  printf("Hello there! I'm process '%d'\n\n", getpid());
  sleep(10);
  printf("I dont vibe with this universe *Explodes* \n\n");

  return 0;
}