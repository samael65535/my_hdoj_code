#include<stdio.h>
int gcd(int a, int b)
{
    return b==0?a:gcd(b,a%b);
}
int main(int argc, char *argv[])
{
  int P;
  scanf("%d", &P);
  while(P--){
    int n,m,k,i;
    scanf("%d%d", &m, &n);
    /* printf ("%d\n", gcd(m,n)); */
    if(gcd(m,n)==1) printf ("NO\n");
    else printf ("YES\n");
  }
  return 0;
}

