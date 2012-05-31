#include<stdio.h>
long long a[101];
int main(int argc, char *argv[])
{
  a[1]=a[0]=1;
  int n, i, j;
  for(i=2;i<10;i++){
    for(j=0;j<i/2;j++){
      a[i] += 2*a[i-1-j]*a[j];
    }
    printf ("%d    %lld\n", i, a[i]);
  }
  while(scanf("%d", &n) != EOF){
printf ("%lld\n", a[n]);
  }
  return 0;
}
