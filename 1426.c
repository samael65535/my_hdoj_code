#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* dfs */
struct node
{
  int x, y;
};
int sodu[9][9];
struct node kk[100];
int s, ok;
int isOK(int x, int y, int z)
{
  /* 看是否符合条件 */
  int i, j;
  int xx=x/3*3;
  int yy=y/3*3;
  for(i=0; i<9; i++)
    if(sodu[y][i]==z) return 0;
  for(i=0; i<9; i++)
    if(sodu[i][x]==z) return 0;
  for(i=yy; i<=yy+2; i++){
    for(j=xx; j<=xx+2; j++)
      if(sodu[i][j]==z) return 0;
  }
  return 1;
}
int dfs(int x)
{
  int i, j;

  if(x==s){ 
    for(i=0; i<9; i++){
      for(j=0; j<8; j++){
	printf ("%d ",sodu[i][j]);
      }
      printf ("%d\n",sodu[i][j]);
    }
    return 1;
  }
  for(i=1; i<10; i++){
    if(isOK(kk[x].x, kk[x].y, i)){
      sodu[kk[x].y][kk[x].x]=i;
      if(dfs(x+1))
	return 1;
      sodu[kk[x].y][kk[x].x]=0;
    }
  }
  return 0;
}
int main()
{
  char tmp[2];
  int ca=0;
  while(scanf("%s", tmp)==1){
    /* 输入数据 */
    int i=0, j=0;
    s=0; ok=0;
    if(tmp[0]=='?'){
      sodu[0][0]=0;
      kk[s].y=0;kk[s++].x=0;
    }
    else sodu[0][0]=tmp[0]-'0';
    for(j=1; j<9; j++){
      scanf("%s", tmp);
      if(tmp[0]=='?'){
	sodu[0][j]=0;
	kk[s].y=0;kk[s++].x=j;
      }
      else sodu[0][j]=tmp[0]-'0';
    }
    for(i=1; i<9; i++){
      for(j=0; j<9; j++){
	scanf("%s", tmp);
	if(tmp[0]=='?'){
	  kk[s].y=i;kk[s++].x=j;
	  sodu[i][j]=0;
	}
	else sodu[i][j]=tmp[0]-'0';
      }
    }
    if(ca)
      printf ("\n");
    dfs(0);
    ca++;
  }
  return 0;
}

