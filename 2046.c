#include<stdio.h>
long long f[52];
int main(int argc, char *argv[])
{
  int n;
  f[1]=1;f[2]=2;
  for(n=3;n<51;n++){
    f[n]=f[n-1]+f[n-2];
  }
  while( scanf("%d", &n)!=EOF){
    printf ("%I64d\n", f[n]);
  }
  return 0;
}
