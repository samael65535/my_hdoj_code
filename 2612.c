/* 忘记而且必须两个人都要走到
吸取教训 淡定~~
----------------------------------------------------------------------------------
亲，你的这个我当时就晕了，还好我随手傻逼的加了一句。。终于过了。。
下面这个列子就是你想说的吧。
input:
5 5
Y..#@
...M#
.....
.....
@....

output:
110 */
#include<stdio.h>
#include<string.h>
char maze[205][205];
int visited[205][205];
int count[205][205];
int count1[205][205];
int x0, y0, x1, y1;
int KFC[400][2];
int queue[50000][2];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int M, N;
void bfs(int x, int y, int k)
{
  int front=0, rear=0;
  int i;
  memset(queue,0,sizeof(queue));
  memset(visited,0,sizeof(visited));
  queue[rear][0]=x; queue[rear++][1]=y;
  visited[x][y]=0;
  if(!k)  count[x][y]=0;
  else  count1[x][y]=0;
  while(front!=rear){
    int xx, yy;
    xx=queue[front][0];
    yy=queue[front][1];
    for(i=0;i<4;i++){
      int tempx, tempy;
      tempx=xx+dir[i][0];
      tempy=yy+dir[i][1];
      if(tempx<0 || tempx>=N || tempy<0 || tempy>=M) continue;
      if(maze[tempx][tempy]=='#') continue;
      if(visited[tempx][tempy]|| (tempx==x&&tempy==y)) continue;
      visited[tempx][tempy]=1;
      if(!k)count[tempx][tempy]=count[xx][yy]+1;
      else{ 
	  count1[tempx][tempy]=count1[xx][yy]+1;
      }
      queue[rear][0]=tempx; queue[rear++][1]=tempy; 
    }
    front++;
  }
}
int main()
{
  while(scanf("%d%d", &N, &M)!=EOF){
    int i,j,x=0;
    memset(KFC,0,sizeof(KFC));
    memset(maze,0,sizeof(maze));
    memset(count,0,sizeof(count));
    memset(count1,0,sizeof(count1));
    for(i=0;i<N;i++) scanf("%s",maze[i]);
    for(i=0;i<N;i++){
      for(j=0;j<M;j++){
	if(maze[i][j]=='Y'){
	  x0=i;y0=j;
	}
	if(maze[i][j]=='M'){
	  x1=i;y1=j;
	}
	if(maze[i][j]=='@'){
	  KFC[x][0]=i;
	  KFC[x++][1]=j;
	  maze[i][j]='.';
	}
      }
    }
    bfs(x0,y0,0);
    bfs(x1,y1,1);
    int min=100000;
    for(i=0; i<x; i++){
      int sum = count[KFC[i][0]][KFC[i][1]]+count1[KFC[i][0]][KFC[i][1]];
      if(min>sum && count[KFC[i][0]][KFC[i][1]] && count[KFC[i][0]][KFC[i][1]])  min=sum;
    }
    printf("%d\n", min*11);
    /* for(i=0;i<N;i++){ */
    /*   for(j=0;j<M;j++){ */
    /* 	printf ("%d\t",count1[i][j]); */
    /*   } */
    /*   printf ("\n"); */
    /* } */
  }
  return 0;
}
