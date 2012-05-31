#include<stdio.h>
#include<string.h>
#define MAXN 105
int courses[MAXN][MAXN];
/* int dp[MAXN][MAXN]; */
int dp[MAXN];
int max(int x, int y)
{
  return x>y?x:y;
}
int main(int argc, char *argv[])
{
  int N, M;
  while(scanf("%d%d", &N, &M)!=EOF && N && M){
    int i, j, m;
    memset(courses, 0, sizeof(courses));
    memset(dp, 0, sizeof(dp));
    for(i=1; i<=N; i++)
      for(j=1; j<=M; j++)
	scanf("%d", &courses[i][j]);
    for(i=1; i<=N; i++){
      for(m=M; m>=0; m--){
	for(j=1; j<=M; j++){
	  /* dp[i][m]=max(dp[i-1][m], dp[i-1][m-j]+courses[i][j]); */
	  if(m>=j)
	    dp[m]=max(dp[m], dp[m-j]+courses[i][j]);
	}
      }
    }
    printf ("%d\n",dp[M]);
  }
  return 0;
}
