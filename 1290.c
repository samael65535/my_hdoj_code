#include<stdio.h>
#include<math.h>
int main()
{
  long long n;
  while(scanf("%lld", &n) != EOF){
    long long sum=(pow(n,3)+5*n+6)/6;
    printf ("%I64d\n", sum);
  }
  return 0;
}

