#include<stdio.h>
 int res[25]={0,0,0,4,6,0,0,12,40,0,0,171,410, 0,0,1896,5160,0,0,32757,59984,0,0,431095,822229};
int main()
{
  int n;
  while(scanf("%d", &n)!=EOF && n){
    printf("%d %d\n", n, res[n]);
  }
  return 0;
}

