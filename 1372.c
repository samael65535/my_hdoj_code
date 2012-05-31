#include<stdio.h>
#include<string.h>
typedef struct{
  int x, y;
}node;
node q[100];
int dir[8][2]={2, -1, 2, 1, -2, -1, -2, 1, 1, 2, 1, -2, -1, 2, -1, -2};
/* int zx[10]={-2,-2,-1, 1, 2, 2, 1,-1}; */
/* int zy[10]={ 1,-1,-2,-2,-1, 1, 2, 2}; */
int step[10][10];
int main(int argc, char *argv[])
{
  char a[2], b[2];
  while(scanf("%c%c %c%c\n", &a[0],&a[1],&b[0], &b[1]) != EOF){
    int x0, y0, x1, y1, x2, y2 , front=0, rear=0, i;
    x0=a[0]-'a'+1;   y0=a[1]-'0';
    x1=b[0]-'a'+1;   y1=b[1]-'0';
    memset(step,0,sizeof(step));
    memset(q,0,sizeof(q));
    step[x0][y0]=1;
    q[rear].x=x0;    q[rear].y=y0;
    while(front<=rear){
      for(i=0; i<8; i++){
	x2=q[front].x+dir[i][0];
	y2=q[front].y+dir[i][1];
	if(x2<1||x2>8||y2<1||y2>8) continue;
	if(step[x2][y2]==0){
	  rear++;
	  q[rear].x=x2;
	  q[rear].y=y2;
	  step[x2][y2]=step[q[front].x][q[front].y]+1;
	}
      }
      front++;
    }
    printf("To get from %c%c to %c%c takes %d knight moves.\n", a[0],a[1], b[0],b[1], step[x1][y1]-1);
  }
  return 0;
}
