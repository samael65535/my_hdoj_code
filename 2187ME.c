/* 多重背包   超时 */
#include<stdio.h>
#include<string.h>
int max(int x, int y)
{
  return x>y?x:y;
}
int main(int argc, char *argv[])
{
  int C;
  scanf("%d", &C);
  while(C--){
    int n, m;
    while(scanf("%d%d", &n, &m)!=EOF){
      int i, j, v;
      int  p[1005], h[1005],x[10005];
      for(i=1; i<=m; i++){
	scanf("%d%d", &p[i], &h[i]);
	h[i]*=100;
	/* printf("%d %d\n", p[i], h[i]); */
      }
      n*=100;
      /* printf ("%d\n", n); */
      memset(x, 0, sizeof(x));
      x[0]=0;
      for(i=1; i<=m; i++){
	for(j=1; j<=h[i]; j++)
	  for(v=n; v>=p[i]; v--){
	    x[v]=max(x[v-p[i]]+1, x[v]);
	  }
      }
      printf ("%.2f\n",(float)x[n]/100);
      /* for(i=1; i<=n; i++) */
      /* 	printf ("%d\t",x[i]); */
    }
  }
  return 0;
}
