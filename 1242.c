/* 求出各个点到‘a’的最近距离，然后从‘r’里面选出能达到的最短距离，考虑‘x’的情况时要保证其他点的最短路不能被破环 */
#include<stdio.h>
#include<string.h>
char maze[202][202];
int step[202][202];
int angelx, angely, r1, r2;
typedef struct {
  int x, y;
}node;
int n, m;
node Queue[40005];
int f[8]={-1,0,0,1,0,-1,1,0}; 	/* 前四个为左右 后四个为上下 */
int fun()
{ 
  int ans=0;
  int front=0, rear=1;
  int x0, y0, x1, y1, i;
  while(front<rear){
    x0=Queue[front].x;
    y0=Queue[front].y;
    for(i=0; i<4; i++){
      x1=x0+f[i];
      y1=y0+f[i+4];
      if(x1>=0 && x1<n && y1>=0 && y1<m && maze[x1][y1]!='#'){
	if(maze[x1][y1]=='x'){
	  if(step[x1][y1]==0 || step[x0][y0]+2<step[x1][y1]){
	    step[x1][y1]=step[x0][y0]+2;
	    Queue[rear].x=x1;
	    Queue[rear++].y=y1;
	  }
	}else{
	  if(step[x1][y1]==0||step[x0][y0]+1<step[x1][y1]){
	    step[x1][y1]=step[x0][y0]+1;
	    Queue[rear].x=x1;
	    Queue[rear++].y=y1;
	  }
	}
      }
    }
    front++;
    /* printf ("%d\n", front); */
  }
  return step[r1][r2];
}
int main(int argc, char *argv[])
{

  while(scanf("%d%d", &n, &m) != EOF){
    int i, j;
    memset(step, 0, sizeof(step));

    for(i=0; i<n; i++){
      scanf("%s", maze[i]);
      for(j=0; j<m; j++){
	if(maze[i][j]=='a'){
	  Queue[0].x=i; Queue[0].y=j;
	}
	if(maze[i][j]=='r'){
	  r1=i; r2=j;
	}
      }
      /* printf("%s\n", maze[i]); */
    }
    /* printf ("%d %d\n", r1,r2); */
    if(i=fun()) printf ("%d\n", fun());
    else  printf("Poor ANGEL has to stay in the prison all his life.\n");

  }
  return 0;
}
