#include<stdio.h>
#include<math.h>
long long f[32];
int main(int argc, char *argv[])
{
  int T;
  f[1]=1;f[2]=3;
  int n;
  for(n=3;n<32;n++){
    f[n]=f[n-1]+2*f[n-2];

  }
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    printf ("%lld\n", f[n]);
  }
  return 0;
}

