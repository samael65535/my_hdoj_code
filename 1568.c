#include<stdio.h>
#include<math.h>
/* 标准的Fibonacci数列F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n - 2)。通项公式为F(n) = (((1+Sqrt(5))/2)^n - ((1-Sqrt(5))/2)^n)*1/Sqrt(5)，因为(1-sqrt(5))/2的绝对值小于1，所以当i较大的时候，往往可以忽略掉这一项F(n)≈((1+Sqrt(5))/2)^n/sqrt(5)。所以Fibonacci前30项可直接求出。后面的大数取log10，取整后求出左边4位， */
int main(int argc, char *argv[])
{
  int n, r, i;
  int fobi[31];
  double tmp = log10(sqrt(5.0));
  double sum = log10((sqrt(5.0)+1.0)/2.0), d;
  fobi[0]=0;fobi[1]=1;
  for(i=2; i<=30; i++){
    fobi[i] = fobi[i-1]+fobi[i-2];
  }
  while(scanf("%d", &n) != EOF) {
    if(n < 31){
      while(fobi[n] >= 10000)
  	fobi[n] /= 10;
      printf("%d\n", fobi[n]);
    }else{
      d = n*sum-tmp;
      d -= (int)d;		/* 去掉整数部分,因为整数部分相当于数后面有几个零 */
      r = pow(10.0,d)*1000.0;
      printf ("%d\n", r);
    }
  }
  return 0;
}
