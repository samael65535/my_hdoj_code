#include<stdio.h>
#include<string.h>
/* 先用DFS把三边消去,再用DFS把符合条件的球掉下 */
char board[105][105];
int visit[105][105];
int dir1[6][2]={-1, -1,
		-1,  0,
		 1,  0,
		 1, -1,
		 0, -1,
		 0,  1};
int dir2[6][2]={ 1, 1,
		 1, 0,
		-1, 0,
		-1, 1,
		 0, -1,
		 0, 1};

char newly;
int sum=0, stat=0;
int H, W, h, w;
void dfs(int h, int w)
{
  int i;
  if(h%2){
    for(i=0; i<6; i++){
      if(board[h+dir1[i][0]][w+dir1[i][1]]==newly && 
	 visit[h+dir1[i][0]][w+dir1[i][1]]==0 &&
	 h<=H && w<=W && h>0 && w>=0){
	stat+=1;
	visit[h+dir1[i][0]][w+dir1[i][1]]=stat;
	dfs(h+dir1[i][0], w+dir1[i][1]);
      }
    }
  }else{
    for(i=0; i<6; i++){
      if(board[h+dir2[i][0]][w+dir2[i][1]]==newly && 
	 visit[h+dir2[i][0]][w+dir2[i][1]]==0 &&
	 h<=H && w<=W && h>0 && w>=0){
	stat+=1;
	visit[h+dir2[i][0]][w+dir2[i][1]]=stat;
	dfs(h+dir2[i][0], w+dir2[i][1]);
      }
    }
  }
}
void dfs2(int h, int w)
{
  int i;
  /* printf ("%d %d\n", h, w); */
  if(h%2){
    for(i=0; i<6; i++){
      if(visit[h+dir1[i][0]][w+dir1[i][1]]==0 &&
	 h<=H && w<=W && h>0 && w>=0){
	visit[h][w]=-1;
	visit[h+dir1[i][0]][w+dir1[i][1]]=-1;
	/* printf ("%d %d\n", h+dir2[i][0], w+dir2[i][1]); */
	dfs2(h+dir1[i][0], w+dir1[i][1]);
      }
    }
  }else{
    for(i=0; i<6; i++){
      if(visit[h+dir2[i][0]][w+dir2[i][1]]==0 &&
	 h<=H && w<=W && h>0 && w>=0){
	visit[h][w]=-1;
	visit[h+dir2[i][0]][w+dir2[i][1]]=-1;
	/* printf ("%d %d\n", h+dir2[i][0], w+dir2[i][1]); */
	dfs2(h+dir2[i][0], w+dir2[i][1]);
      }
    }
  }
}
int main(int argc, char *argv[])
{
  while(scanf("%d%d%d%d", &H,&W,&h,&w)!=EOF){
    int i, j;
    memset(board, 0, sizeof(board));
    memset(visit, 0, sizeof(visit));
    for(i=1; i<=H; i++){
      scanf("%s", board[i]);
      if(i%2==0) visit[i][W-1]=-1;
      for(j=0; j<strlen(board[i]); j++)
	if(board[i][j]=='E') visit[i][j]=-1;
    }
    newly=board[h][w-1];
    sum=0;
    stat=1;
    visit[h][w-1]=1;
    dfs(h, w-1);		/* 消球 */
    if(stat>=3){
      for(i=0; i<W; i++){
	if(visit[1][i]==0){
	  visit[0][i]=-1;
	  dfs2(1, i);
	}
      }
    }
    for(i=1; i<=H; i++){
      for(j=0; j<W; j++){
	/* printf ("%d\t", visit[i][j]); */
	if(visit[i][j]==0){
	  sum++;
	}
      }
      /* printf ("\n"); */
    }
    if(stat>=3)
      printf ("%d\n", stat+sum);
    else
      printf ("0\n");
  }
  return 0;
}
