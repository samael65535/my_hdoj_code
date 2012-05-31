#include<stdio.h>
int gcd(int a, int b)
{
  return b==0?a:gcd(b, a%b);
}
int main(int argc, char *argv[])
{
  int T;
  scanf("%d", &T);
  while(T--){
    int a, b, c, d;
    scanf("%d%d%d%d", &a,&b,&c,&d);
    int f=gcd(a*d+b*c, b*d);
    /* printf ("%d\n", f); */
    printf ("%d %d\n",(a*d+b*c)/f, b*d/f);
  }
  return 0;
}

