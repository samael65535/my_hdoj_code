#include<stdio.h>
#include<stdlib.h>
/* 假设A中去掉的数在第k+1位，可以把A分成三部分，低位，k，和高位。

A == a + b * 10^k + c * 10^(k+1)

B == a          +         c * 10^k

N == A + B == 2 * a + b * 10^k + c * 10^k * 11

其中b是一位数， b * 10^k 不会进位，用 10^k 除 N 取整就可以得到 b + 11c ，再用 11 除，商和余数就分别是 c 和 b 了。但是这里有个问题 a 是一个小于 10^k 的数没错，但是 2a 有可能产生进位，这样就污染了刚才求出来的 b + 11c 。但是没有关系，因为进位最多为 1 ，也就是 b 可能实际上是 b+1 ， b 本来最大是 9 ，那现在即使是 10 ，也不会影响到除 11 求得的 c 。因此 c的值是可信的。然后根据 2a 进位和不进位两种情况，分别考虑 b 要不要 -1 ，再求 a ，验算，就可以了。

迭代k从最低位到最高位做一遍，就可以找出所有可能的 A 。


 */
int cmp(const void *a,const void *b)
{
 return *(int *)a-*(int *)b;
}
int main()
{
 int n,i,k,a,b,c,x[20];
 while(scanf("%d",&n)&&n)
 {
  i=0;
  for(k=1;k<=n;k*=10)
  {
   c=(n/k)/11;
   b=n/k-c*11;
   if((b!=0||c!=0)&&b<10)
   {
    a=(n-b*k-c*11*k)/2;
    if(2*a+b*k+c*11*k==n)
     x[i++]=a+b*k+c*10*k;
   }
   b--;
   if((b!=0||c!=0)&&b>=0)
   {
    a=(n-b*k-c*11*k)/2;
    if(2*a+b*k+c*11*k==n)
     x[i++]=a+b*k+c*10*k;
   }
  }
  if(i)
  {
   qsort(x,i,sizeof(x[0]),cmp);
   printf("%d",x[0]);
   for(k=1;k<i;++k)
   {
    if(x[k]!=x[k-1]) printf(" %d",x[k]);
   }
   puts("");
  }
  else printf("No solution.\n");
 }
 return 0;
}
