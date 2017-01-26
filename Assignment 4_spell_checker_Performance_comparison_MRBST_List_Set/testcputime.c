#include <stdio.h>
#include <unistd.h>
#include "cputime.h"


int main(void)
{
  double t1, t2;
  
  t1 = cputime();
  sleep(1);
  t2 = cputime();
  
  printf("Time taken= %fs; it should be around 1s\n", t2-t1);
  
  t1 = cputime();
  while( (t2=cputime()) == t1)
    ;
  
  printf("Timer resolution = %f microseconds\n", 1000000*(t2-t1));
  
  return 0;
}


