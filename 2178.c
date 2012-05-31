#include<stdio.h>
#include<math.h>
int main(int argc, char *argv[])
{
  int T;
  scanf("%d", &T);
  while(T--){
    int n, i=0, r,l;
    scanf("%d", &n);
    printf("%I64d\n", (long long)pow(2,n)-1);
  }
  return 0;
}
