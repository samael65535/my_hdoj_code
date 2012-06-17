#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n, m, t, kx, ky;
char maze[8][8];
int visit[8][8];
int ans;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
void dfs(int x, int y, int time)
{
  int i;
  int temp;
  if(time>t) return;
  temp=(t-time)-abs(x-kx)-abs(y-ky);
  if(temp<0||temp%2==1) return;
  int tx, ty;
  for(i=0; i<4; i++){
    ty=y+dy[i];
    tx=x+dx[i];
    if(maze[ty][tx]=='D' && time==t-1){ /* 要放在循环体内否则根据下面的 maze[ty][tx]=='.' 不会执行 */
      ans=1;
      return;
    }
    if(tx<0 || tx>=m || ty<0 || ty>=n) continue;
    if(maze[ty][tx]=='X') continue;
    if(visit[ty][tx]==1) continue;
    if(ans) return;
    if(maze[ty][tx]=='.'){
      visit[ty][tx]=1;
      dfs(tx, ty,time+1);   
      visit[ty][tx]=0;
    }
  }
}
int main()
{
  while(scanf("%d%d%d", &n, &m, &t)!=EOF && (n || m || t)){
    int i, j, x, y, wall=0;
    memset(maze, 0, sizeof(maze));
    memset(visit, 0, sizeof(visit));
    for(i=0; i<n; i++){
      scanf("%s", maze[i]);
      for(j=0; j<m; j++){
	if(maze[i][j]=='S'){
	  y=i;x=j;
	}
	if(maze[i][j]=='D'){
	  kx=j; ky=i;
	}
	if(maze[i][j]=='X'){
	  visit[i][j]=1;
	  wall++;
	}
      }
    }
    if(n*m-wall<=t){
      printf("NO\n");
      continue;
    }
    ans = 0;
    visit[y][x]=1;
    dfs(x, y, 0);
    if(!ans) printf("NO\n");
    else printf("YES\n");
  }
  return 0;
}
