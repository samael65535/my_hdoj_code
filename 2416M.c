#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
/* 思路先把每个洞的路线记下再计算最优 */
#define MAX 100000
char maze[105][105];
int visited[105][105];
char temp[105];
int point[105][3];
int dx, dy;
int dir[4][2]={1, 0, -1, 0, 0, 1, 0, -1}; /* right, left, down, up */
int queue[10000][2];
int count[10000];
int ans=MAX, lines;
int min(int a, int b)
{
  return a<b?a:b;
}
int cmp(const void *a, const void *b)
{
  return *(int *)b+*(int *)a;
}
int cost(int booms)
{
  int len=0, i, time=0;
  while(count[len++]);
  qsort(count, len,sizeof(int), cmp);
  printf ("BOOM %d\n", booms);
  for(i=booms; i<len; i++)
    time+=count[i];
  printf ("time %d\n",time);
  return time;
}
int fun(int x, int y, int z)
{
  int front=0, rear=0, i=0, j=0; 
  int tempx, tempy;
  int s=0, min=MAX;
  memset(queue, 0, sizeof(queue));
  queue[rear][0]=x; queue[rear++][1]=y;
  while(front<rear){
    for(i=0; i<4; i++){
      tempx=queue[front][0];
      tempy=queue[front][1];
      tempx+=dir[i][0];
      tempy+=dir[i][1];
      if(maze[tempy][tempx]=='*' || visited[tempy][tempx]==1) continue;
      if(tempx<0 || tempx>=strlen(maze[0]) || tempy>=lines || tempy<0) continue;
      if(isdigit(maze[tempy][tempx])) count[j++]=maze[tempy][tempx]-'0';
      if(maze[tempy][tempx]=='$'){
	int t=cost(z);
	if(t>min);
	else min=min>t?t:min;
	/* printf ("%d\t%d\t%d\n",tempy, tempx, t); */
	/* printf ("%d\t%d\t%d\n",x, y, z); */
	/* printf ("min  %d\n", min); */
	memset(count, 0, sizeof(count));
	break;
      }
      visited[tempy][tempx]=1;
      queue[rear][0]=tempx; queue[rear++][1]=tempy;
    }
    front++;
  }
  return min;
}
int main()
{
  int flag=1;
  while(flag){
    int i=0,j=0,x=0;
    lines=0;
    memset(maze, 0, sizeof(maze));
    memset(visited, 0, sizeof(visited));
    while(gets(maze[lines])){
      if(strlen(maze[lines])<1) break;
      if(maze[lines][0]=='-') return 0;
      lines++;
    }
    for(i=0; i<lines; i++){
      for(j=0; j<strlen(maze[0]); j++){
	if(isupper(maze[i][j]) || maze[i][j]=='#'){ 
	  point[x][0]=j;point[x][1]=i; 
	  if(maze[i][j]=='#') point[x][2]=0;
	  else{point[x][2]=maze[i][j]-'A'+1;}
	  x++;
	  visited[i][j]=1;
	}
	if(maze[i][j]=='$'){
	  dx=i;
	  dy=j;
	}
      }
    }
    int t;
    ans=MAX;
    for(i=0;i<x;i++){

      memset(count, 0, sizeof(count));
      t=fun(point[i][0], point[i][1], point[i][2]);
      ans=ans>t?t:ans;
    }
    if(ans==MAX) printf ("OK\n");
    else printf("%d\n", ans);
  }
  return 0;
}
