#include<stdio.h>
/* 注意边界测试 1073741824 1073741824 */
int main()
{
  int a, b;
  while(scanf("%d%d",&a, &b)!=EOF){
    int res[4], i;
    a=a%10;
    res[0]=a;
    /* printf ("%d\n",res[0]); */
    for(i=1; i<4; i++){
      int tmp=res[i-1]*a;
      res[i]=tmp%10;
      /* printf ("%d %d\n", i,res[i]); */
    }
    printf ("%d\n",res[(b-1)%4]);
  }
  return 0;
}
