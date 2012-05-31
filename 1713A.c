#include<stdio.h>
#include<string.h>

long long gcd(long long a,long long b)
{
 while(a>b?(a%=b):(b%=a));return a+b;
}
int main()
{
 int t;
 long long a,b,c,d;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%lld/%lld%lld/%lld",&a,&b,&c,&d);
  a=a*d*c*b/gcd(a*d,c*b);
  b=b*d;
  if(a%b) {
    c=gcd(a,b); printf("%lld/%lld\n",a/c,b/c);}
  else printf("%lld\n",a/b);
 }
 return 0;
}
