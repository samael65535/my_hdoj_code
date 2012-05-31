#include<stdio.h>
#include<string.h>
#define INF 999999
#define MAXN 10005
int f[102][MAXN];
int n[MAXN], c[MAXN], w[MAXN];
int max(int x, int y)
{
  return x>y?x:y;
}

int main(int argc, char *argv[])
{
  int N,V,K;
  while(scanf("%d%d%d", &N, &V ,&K) !=EOF){
    int i, j, k, l;
    for(i=1; i<=N; i++){
      scanf("%d%d%d", &n[i], &c[i], &w[i]);
    }
    for(i=1;i<=K;i++)
      for(j=0;j<=V;j++)
    	f[i][j] = -INF;

    for(i=1; i<=K; i++){	/* 编号  */
      for(j=1; j<=N; j++){
	if(n[j]==i){		/* 分类编号 */
	  for(l=V; l>=c[j]; l--){
	    f[i][l]=max(f[i][l], f[i][l-c[j]]+w[j]);
	    f[i][l]=max(f[i][l], f[i-1][l-c[j]]+w[j]);
	    /* printf ("%d\n",f[j][l]);       */
	  }
	}
      }
    }
    if(f[K][V] < 0)
      printf ("Impossible\n");
    else printf("%d\n",f[K][V]);
  }
  return 0;
}
