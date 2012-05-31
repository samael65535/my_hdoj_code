#include<stdio.h>
int  gcd(int a, int b)
{
  return b==0?a:gcd(b,a%b);

}
int main(int argc, char *argv[])
{
  int n, m;
  while(scanf("%d%d", &n, &m) != EOF && n!=-1 && m!=-1){
    int t;
    if(m>n){
      t=m; m=n; n=t;
    }
    printf ("%s\n", gcd(n, m)==1?"YES":"POOR Haha");
  }
  return 0;
}
