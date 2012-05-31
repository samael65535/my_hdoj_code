#include<stdio.h>
long long f[52];
int main(int argc, char *argv[])
{
  int n;
  f[1]=f[2]=1;
  for(n=3;n<51;n++){
    f[n]=f[n-1]+f[n-2];
  }
  scanf("%d", &n);
  while(n--){
    int a, b;
    scanf("%d%d", &a, &b);
    printf ("%I64d\n", f[b-a+1]);
  }
  return 0;
}
