#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
  return *(int *)a-*(int *)b;	/* 注意格式 */
}
int bigger(int x, int y)
{
  return x>y?x:y;
}
int main(int argc, char *argv[])
{
  int n;
  while(scanf("%d", &n) !=EOF && n){
    int money, limit, s=0;
    int i, j, f[1005]={0}, sum[1005*2]={0};
    for(i=0; i<n; i++){
      scanf("%d", &f[i]);
    }
    scanf("%d", &money);
    if(money<5){
      printf ("%d\n", money);
      continue;
    }
    qsort(f, n, sizeof(f[0]), cmp);
    limit=money-5;
    for(i=0; i<n-1; i++){
      for(j=limit; j>=f[i]; j--){
	sum[j]=bigger(sum[j], sum[j-f[i]]+f[i]);
      }
    }
    /* printf ("%d\t%d\n",max,f[n-1]); */
    printf ("%d\n", money-sum[limit]-f[n-1]);
    /* printf ("\n"); */
    /* printf ("\n%d\n\n", money-sum[n-1]-f[n-1]); */
    /* printf ("\n%d\n", max); */
  }
  return 0;
}
