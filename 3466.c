#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
  int Pi;
  int Qi;
  int Vi;
  int qp;
}Item;

int cmp(const void *a, const void *b)
{
  Item *x=(Item *)a; 
  Item *y=(Item *)b; 
  return x->qp - y->qp;
}
int max(int x, int y)
{
  return x>y?x:y;
}
int main(int argc, char *argv[])
{
  int N, M;
  while(scanf("%d%d", &N, &M)!=EOF){
    Item item[5005];
    int dp[5005];
    int i, j;
    memset(dp, 0, sizeof(dp));
    memset(item, 0, sizeof(item));
    for(i=0; i<N; i++){
      scanf("%d%d%d", &item[i].Pi, &item[i].Qi, &item[i].Vi);
      item[i].qp=item[i].Qi-item[i].Pi;
    }
    qsort(item, N, sizeof(item[0]),  cmp);
    for(i=0; i<N; i++){
      for(j=M; j>=item[i].Pi; j--){
	if(j>=item[i].Qi)	/*  不能低于Qi */
	  dp[j]=max(dp[j], dp[j-item[i].Pi]+item[i].Vi);
      }
    }
    j=-1;
    for(i=0; i<=M; i++) j=max(j, dp[i]);
    printf ("%d\n", dp[M]);
  }

  return 0;
}
