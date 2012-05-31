#include<stdio.h>
#include<string.h>
int max(int x, int y)
{
  return x>y?x:y;
}
int main(int argc, char *argv[])
{
  int N, C;
  while(scanf("%d%d", &N, &C)!=EOF){
    int i, j, k, v, l, c, amount=0;
    int words[15][15];		/* 用矩阵坐轴表示复杂度与价值,交点表示次数 */
    int dp[100000];
    char s[20];
    memset(dp, 0, sizeof(dp));
    memset(words, 0, sizeof(words));
    for(i=1; i<=N; i++){
      scanf("%s", s);
      scanf("%d%d",&v, &c);
      words[v][c]+=1;
    }
    for(v=1; v<15; v++){
      for(c=1; c<15; c++){
	if(words[v][c]!=0){
	  amount=words[v][c];
	  int sum=0, count=1;
	  while(sum<amount){
	    for(l=C; l>=c*count; l--){
	      dp[l]=max(dp[l], dp[l-count*c]+v*count);
	    }
	    sum+=count;
	    if(amount-sum<count*2)
	      count=amount-sum;
	    else
	      count*=2;
	  }
	}
      }
    }
    printf ("%d\n",dp[C]);
  }
  return 0;
}

