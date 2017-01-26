#include "cputime.h"
#include <cmath>
#include <iostream>

using namespace std;

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

  cout << "Resolution of rdtsc  = " << (t2-t1)*iCPS << "s\n\n";

  t1 = cputime();
  for(i=0; i<N; i++)
    x += sin((double) i + x);
  t2 = cputime();

  cout << "Time = " << (t2-t1)*iCPS << "s\n\n";

  return 0;
}



