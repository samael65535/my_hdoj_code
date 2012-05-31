#include<stdio.h>
/* 输入 a/b c/d
转换后变成：
(a*d)/(b*d) 和 (c*b)/(b*d)
按照题意，就是在转相同的圈子(b*d圈)时，各自需要时间a*d和c*b.
所以，这里把a*d与c*b的最小公倍数求出来就可以了。
这样。求出的最小公倍数lcm再除以(b*d)就是所求的周期。
但是，这里要求若无法整出，则写出分数形式，这时，
就可以求lcm与(b*d)的最大公约数gcd,
求出gcd后与(b*d)比较，若相等，则证明可以整除~~~~ */

 /* 用%lld 超时,要用%I64d */

long long gcd(long long a, long long b)
{
  while(a>b?(a%=b):(b%=a));
  return a+b;
}

int main(int argc, char *argv[])
{
  long long n;
  long long a, b, c, d;
  scanf("%lld", &n);
  while(n--){
    scanf("%lld/%lld%lld/%lld", &a, &b, &c ,&d);
    a=a*d*c*b/gcd(a*d,c*b);
    b=b*d;
  if(a%b){
      c = gcd(a, b);
      printf ("%lld/%lld\n",a/c, b/c);
    }
    else printf ("%lld\n", a/b);
      
  }
  return 0;
}
