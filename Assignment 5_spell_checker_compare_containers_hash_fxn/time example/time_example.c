#include <stdio.h>
#include "cputime.h"
#include <math.h>


int main(int argc, char **argv)
{
  unsigned long long t1, t2;
  int i, N=100000000;
  double x;
  
  t1 =  cputime();
  do
    {
      t2 =  cputime();
    } while(t1 == t2);

  printf("Resolution of rdtsc  = %g s, %llu, %llu\n\n", (t2-t1)*iCPS, t2, t1);

  t1 = cputime();
  for(i=0; i<N; i++)
    x += sin((double) i + x);
  t2 = cputime();

  printf("Time = %gs\n\n", (t2-t1)*iCPS);

  return 0;
}



