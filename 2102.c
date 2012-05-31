/* bfs  WA:把坐标搞反了 */
#include<stdio.h>
#include<string.h>
typedef struct{
  int x, y, f,t;
}Point;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
Point queue[10000];
char maze[2][12][12];
int visit[2][12][12];
int T, N, M;
int f0,x0,y0;
int f1,x1,y1;
void search()
{
  int front=0, rear=0;
  int i;
  Point q,temp;
  q.x=x1; q.y=y1; q.f=f1; q.t=0;
  visit[q.f][q.x][q.y]=0;
  queue[rear++]=q;
  while(front!=rear){
    q=queue[front];
    for(i=0; i<4; i++){
      temp=q;
      temp.x=q.x+dir[i][0];
      temp.y=q.y+dir[i][1];
      if(temp.x<0 || temp.y<0 || temp.x>=M || temp.y>=N) continue;
      if(maze[temp.f][temp.y][temp.x]=='#'){
      	visit[temp.f][temp.y][temp.x]=-2;
      	temp.f=!temp.f;
      }
      if(maze[temp.f][temp.y][temp.x]=='*') continue;
      if(visit[temp.f][temp.y][temp.x]!=-1) continue;
      if(maze[temp.f][temp.y][temp.x]=='#') continue;
      temp.t+=1;
      visit[temp.f][temp.y][temp.x]=temp.t;
      queue[rear++]=temp;

    }

    front++;
  }
}
int main(int argc, char *argv[])
{
  int C,i,j,k;
  scanf("%d", &C);
  while(C--){
    scanf("%d%d%d", &N, &M, &T)!=EOF;
    memset(queue, 0, sizeof(queue));
    memset(maze, 0, sizeof(maze));
    memset(visit, -1, sizeof(visit));
    for(i=0; i<N; i++) scanf("%s",maze[0][i]);
    for(i=0; i<N; i++) scanf("%s",maze[1][i]);
    for(k=0; k<2;k++){
      for(i=0; i<N; i++){
	for(j=0; j<M; j++){
	  if(maze[k][i][j]=='P'){
	    maze[k][i][j]='.';
	    f0=k;x0=i;y0=j;
	  }
	  if(maze[k][i][j]=='S'){
	    maze[k][i][j]='.';
	    f1=k;x1=i;y1=j;
	  }
	}
      }
    }
    search();

    if(visit[f0][x0][y0]<=T && visit[f0][x0][y0]>=0) printf("YES\n");
    else printf("NO\n");
    /* for(k=0; k<2;k++){ */
    /*   for(i=0; i<N; i++){ */
    /* 	for(j=0; j<M; j++){ */
    /* 	  printf ("%d\t", visit[k][i][j]); */
    /* 	} */
    /* 	printf ("\n"); */
    /*   } */
    /*   printf ("\n"); */
    /* } */
  }
  return 0;
}

