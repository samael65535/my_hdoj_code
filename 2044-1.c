#include<stdio.h>
long long sum;
/* int count(int a, int b) */
/* { */
/*   if(a>b) return 0; */
/*   if(b==a){ */
/*     sum+=1; */
/*     return 0; */
/*   }else{ */
/*     count(a+1, b); */
/*     count(a+2, b); */
/*   } */
/* } */
int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  while(n--){
    int a, b;
    scanf("%d%d", &a, &b);
    count(a,b);
    printf ("%lld\n", sum);
    sum = 0;
  }
  return 0;
}
