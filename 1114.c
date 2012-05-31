#include<stdio.h>
#include<stdlib.h>
#define INF 99999999
#define MAX 1005
int min(int x, int y)
{
  return x<y?x:y;
}
int main(int argc, char *argv[])
{
  int T;
  scanf("%d", &T);
  while(T--){
    int empty, filled, n, pig;
    int v[MAX], w[MAX], dp[10050];
    scanf("%d%d",&empty, &filled);
    pig = filled-empty;
    scanf("%d", &n);
    int i, j;
    for(i=0; i<n; i++)
      scanf("%d%d", &v[i], &w[i]);
    for(i=0; i<=pig; i++)
      dp[i]=INF;
    dp[0]=0;
    for(i=0; i<n; i++){
      for(j=w[i]; j<=pig; j++){
	dp[j]=min(dp[j], dp[j-w[i]]+v[i]);
      }
    }
    if(dp[pig]==INF) 
      printf ("This is impossible.\n");
    else 
      printf ("The minimum amount of money in the piggy-bank is %d.\n", dp[pig]);
  }
  return 0;
}
