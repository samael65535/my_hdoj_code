#include<stdio.h>
long long cow[55];
int main(int argc, char *argv[])
{
  int n, i;
  cow[1]=1;cow[2]=2;cow[3]=3;
  for(i=1;i<52;i++){
    cow[i+3] = cow[i+2] + cow[i];
  }
  while(scanf("%d", &n) != EOF && n){
    printf ("%I64d\n", cow[n]);
  }
  return 0;
}
