#include<stdio.h>
#include<string.h>

int bigger(int x, int y)
{
  return x>y?x:y;
}

int main(int argc, char *argv[])
{
  int N, C;
  while(scanf("%d%d", &N, &C)!=EOF){
    int i, j, k, l, v, c;
    char s[20];
    int words[15][15];		/* 用矩阵坐轴表示复杂度与价值,交点表示次数 */
    int dp[9999];
    memset(dp, 0, sizeof(dp));
    memset(words, 0, sizeof(words));
    for(i=1; i<=N; i++){
      scanf("%s", s);
      scanf("%d%d",&v, &c);
      words[v][c]+=1;;
      /* printf ("%d\n",i); */
    }
    for(v=1; v<15; v++){
      for(c=1; c<15; c++){
	if(words[v][c]>=1){
	  /* printf ("%d\t%d\t%d\n",words[v][c],v,c); */
	  for(k=C; k>=c; k--){
	    for(i=1; i<=words[v][c]; i++){
	      dp[k] = bigger(dp[k],dp[k-i*c]+i*v);
	      /* printf ("%d\t%d\t",v,c); */
	    }
	  }
	}
      }
    }
    printf ("%d\n",dp[C]);
  }
  return 0;
}

