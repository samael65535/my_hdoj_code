#include<stdio.h>
#include<math.h>
/* 注意(最大)公约的概念 a=12 b=2 c应该为10 */
int gcd(int a, int b)
{
  return a%b?gcd(b, a%b):b;
}
int main(int argc, char *argv[])
{
  int N;
  scanf("%d", &N);
  while(N--){
    int a, b, c;
    int i;
    scanf("%d%d", &a, &b);
    c=b+1;
    while(gcd(a,c)!=b){
      c++;
    }
    printf ("%d\n", c);
  }
  return 0;
}
