#include<stdio.h>
#define MAX 10005
#define INF 999999
int n[MAX], c[MAX], w[MAX], f[105][MAX];
int max(int x, int y)
{
  return x>y?x:y;
}
int main(int argc, char *argv[])
{
  int N,V,K;
  while(scanf("%d%d%d", &N, &V ,&K) !=EOF){
    int i, j, k;
    for(i=1; i<=N; i++){
      scanf("%d%d%d", &n[i], &c[i], &w[i]);
    }
    for(i=1;i<=K;i++)
      for(j=0;j<=V;j++)
	f[i][j] = -INF;
    for(k=1;k<=K;k++)
      for(i=1;i<=N;i++)
{
	  if(n[i]==k)
	    {
	      for(j=V;j>=c[i];j--)
		{
		  f[k][j] = max(f[k][j], f[k][j-c[i]]+w[i]);
		  f[k][j] = max(f[k][j], f[k-1][j-c[i]]+w[i]);
		}
	    }
	}
    if(f[K][V] < 0)
      printf ("Impossible\n");
    else printf("%d\n",f[K][V]);
  }
  return 0;
}
