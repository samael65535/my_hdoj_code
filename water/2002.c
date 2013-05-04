#include<stdio.h>
#include<math.h>
#define PI 3.1415927
int main(int argc, char *argv[])
{
  double n;
  while(scanf("%lf", &n)!=EOF){
    printf ("%.3lf\n",4*PI*pow(n,3)/3);
  }
  return 0;
}
