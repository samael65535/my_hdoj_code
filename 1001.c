#include<stdio.h>
int main(int argc, char *argv[])
{
  long long n;
  while(scanf("%lld", &n) == 1){
    printf("%lld\n", (1+n)*n/2);
  }
  return 0;
}
