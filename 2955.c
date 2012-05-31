#include<stdio.h>
#include<string.h>
#define MAXN 105
typedef struct{
  int Mj;
  float Pj;
}Bank;
float dp[100005];
float max(float x, float y)
{
  return x>y?x:y;
}
int main(int argc, char *argv[])
{
  int T;
  scanf("%d", &T);
  while(T--){
    float P;
    int N, i, j, sum=0;
    Bank b[105];
    memset(b, 0, sizeof(b));	/* 注意要初始化 */
    memset(dp, 0, sizeof(dp));
    scanf("%f%d", &P, &N);
    for(i=1; i<=N; i++){
      scanf("%d%f", &b[i].Mj, &b[i].Pj);
      b[i].Pj=1.0-b[i].Pj;
      sum+=b[i].Mj;
    }
    dp[0]=1.0;
    for(i=1; i<=N; i++){
      for(j=sum; j>=b[i].Mj; j--)
	dp[j]=max(dp[j], dp[j-b[i].Mj]*b[i].Pj);
    }
    for(j=sum; j>=0; j--){
      if(dp[j]>=1-P) {
	printf ("%d\n",j);
	break;
      }
    }
  }
  return 0;
}
