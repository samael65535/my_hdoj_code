#include<stdio.h>
#include<math.h>
int main(int argc, char *argv[])
{
  double r;
  while(scanf("%lf", &r)!=EOF){
    printf ("%.2lf\n", fabs(r));
  }
  return 0;
}
