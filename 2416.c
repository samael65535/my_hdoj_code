#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 1000000
/* 动态规划, visited第三维表示用了炸弹数的最小花费时间,所以门都要广搜 */
struct{
  int x, y, time, booms;
}queue[MAX];
char maze[105][105];
int visited[105][105][27];
int dir[4][2]={1, 0, -1, 0, 0, 1, 0, -1}; /* right, left, down, up */
int lines, col;
int checkhelp(int cy, int cx, int tmp, int v){
  return visited[cy][cx][tmp]==-1 || visited[cy][cx][tmp]>v;
}
int fun()
{
  int i=0, j=0; 
  int front=0, rear=0;
  int tempx, tempy;
  int ans=MAX;
    memset(visited, -1, sizeof(visited));
  for(i=0; i<lines; i++){
    for(j=0; j<col; j++){
      if(isupper(maze[i][j]) || maze[i][j]=='#'){ 
	queue[rear].x=j;
	queue[rear].y=i;
	queue[rear].time=0;
      	if(maze[i][j]=='#') queue[rear].booms=0;
	else queue[rear].booms=maze[i][j]-'A'+1;
	visited[i][j][queue[rear].booms]=0;
	rear++;
      }
    }
  }
  while(front<rear){
    for(i=0; i<4; i++){
      tempx=queue[front].x+dir[i][0];
      tempy=queue[front].y+dir[i][1];
      if(tempx<0 || tempx>=col || tempy>=lines || tempy<0 
	 || maze[tempy][tempx]=='*' || maze[tempy][tempx]=='#') continue;
      if(maze[tempy][tempx]=='.' && 
	 checkhelp(tempy, tempx, queue[front].booms, queue[front].time)){
	visited[tempy][tempx][queue[front].booms] = queue[front].time;
	queue[rear].x=tempx;
	queue[rear].y=tempy;
	queue[rear].time=queue[front].time;
	queue[rear].booms=queue[front].booms;
	rear++;
      }else if(isdigit(maze[tempy][tempx])){
	if(queue[front].booms>0 && 
	   checkhelp(tempy,tempx,queue[front].booms-1,queue[front].time)){

	  visited[tempy][tempx][queue[front].booms-1]=queue[front].time;
	  queue[rear].x=tempx;
	  queue[rear].y=tempy;
	  queue[rear].time=queue[front].time;
	  queue[rear].booms=queue[front].booms-1;
	  rear++;
	}
	if(checkhelp(tempy, tempx, queue[front].booms, 
		     queue[front].time+maze[tempy][tempx]-'0')){
	  visited[tempy][tempx][queue[front].booms] 
	    = queue[front].time+maze[tempy][tempx]-'0';
	  queue[rear].x=tempx;
	  queue[rear].y=tempy;
	  queue[rear].time = queue[front].time+maze[tempy][tempx]-'0';
	  queue[rear].booms=queue[front].booms;
	  rear++;
	}
      }else if(maze[tempy][tempx]=='$'){
	if(ans>queue[front].time)
	  ans=queue[front].time;
      }
    }
    front++;
  }
  return ans;
}
int main()
{
  int flag=1;
  while(flag){
    lines=0;
    col=0;

    while(gets(maze[lines])){
      if(strlen(maze[lines])<1) break;
      if(maze[lines][0]=='-') return 0;
      lines++;
    }
    col=strlen(maze[0]);
    int t=fun();
    if(t==MAX) printf ("IMPOSSIBLE\n");
    else printf("%d\n", t);
  }
  return 0;
}
