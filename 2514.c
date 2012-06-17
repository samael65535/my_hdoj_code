#include<stdio.h>
#include<string.h>
int map[8][8]={
/*a b c d e f g h*/
  0,1,1,1,0,0,0,0,		/* A */
  1,0,1,0,1,1,0,0,		/* B */
  1,1,0,1,1,1,1,0,		/* C */
  1,0,1,0,0,1,1,0,		/* D */
  0,1,1,0,0,1,0,1,		/* E */
  0,1,1,1,1,0,1,1,		/* F */
  0,0,1,1,0,1,0,1,		/* G */
  0,0,0,0,1,1,1,0		/* H */
};	
int num[8], sum, show[8];
int vis[9];
int isOK(int pos, int n)
{
  /* 是否访问过,是否连接*/
  int i;
  if(vis[n]) return 0;
  for(i=0; i<8; i++){
    if(map[pos][i]==1){
      if(n==1 && num[i]==2)
	return 0;
      if(n==8 && num[i]==7)
	return 0;
      if(n>1&&n<8)		/* 注意这个情况,不能直接if */
	if(num[i]==n-1 || num[i]==n+1)
	  return 0;
    }
  }
  return 1;
}
void dfs(int k)
{
  int i;
  if(sum>1) return;
  if(k==8){
    sum++;
    for(i=0; i<8; i++)
      show[i]=num[i];
  }
  if(num[k]>0)     dfs(k+1);
  else{
    for(i=1; i<=8; i++){
      if(isOK(k, i)){
	num[k]=i;
	vis[i]=1;
	dfs(k+1);
	num[k]=0;
	vis[i]=0;
      }
    }
  }
  return;
}
int main()
{
  int n, k=1;
  scanf("%d", &n);
  while(n--){
    int i, j;
    sum=0;
    memset(vis, 0, sizeof(vis));
    memset(show, 0, sizeof(show));
    vis[0]=1;
    for(i=0; i<8; i++){
      scanf("%d", &num[i]);
      vis[num[i]]=1;
    }
    printf("Case %d: ", k++);
    dfs(0);
    if(sum>1) printf("Not unique\n");
    else if(sum==0)printf("No answer\n");
    else if(sum==1){
      for(i=0; i<7; i++){
	printf ("%d ",show[i]);
      }
      printf ("%d\n", show[i]);
    }
  }
  return 0;
}
