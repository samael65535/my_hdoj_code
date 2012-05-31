#include<stdio.h>
#include<string.h>
typedef struct{
  int num[4];
  int step;
}Node;
int visit[10][10][10][10];
Node q[10005];
int from[4], to[4];
int dir[8][4]={{1,0,0,0}, {-1,0,0,0},
	       {0,1,0,0}, {0,-1,0,0},
	       {0,0,1,0}, {0,0,-1,0}, 
	       {0,0,0,1}, {0,0,0,-1}};
int check(Node temp)
{
  if(visit[temp.num[0]] [temp.num[1]] [temp.num[2]] [temp.num[3]]==0) return 1;
  return 0;
}
void fun()
{
  int front=0, rear=0;
  int i,j,k,steps=1000005;
  Node temp, now;
  q[rear].num[0]=from[0];  q[rear].num[1]=from[1];
  q[rear].num[2]=from[2];  q[rear].num[3]=from[3];
  q[rear++].step=0;
  while(front<rear){
    now=temp=q[front];
    for(j=0; j<8; j++){
      temp=now;
      if(temp.num[0]==to[0] && temp.num[1]==to[1] && temp.num[2]==to[2] && temp.num[3]==to[3]){
	steps=temp.step<steps?temp.step:steps;
      }
      for(i=0; i<4; i++){ 
	temp.num[i]+=dir[j][i];
	if(temp.num[i]>9) temp.num[i]=1;
	if(temp.num[i]<1) temp.num[i]=9;
	/* printf("%d,%d,%d,%d\n", temp.num[0], temp.num[1], temp.num[2], temp.num[3]); */
      }
      if(check(temp)){
	temp.step+=1;
	q[rear++]=temp;
	visit[temp.num[0]] [temp.num[1]] [temp.num[2]] [temp.num[3]]=1;
      }
    
      for(i=0; i<3; i++){	/* 少交换一位下次注意 */
	int t;
	temp=now;
	t=temp.num[i+1];
	temp.num[i+1]=temp.num[i];
	temp.num[i]=t;
	if(check(temp)){
	  temp.step+=1;
	  q[rear++]=temp;
	  visit[temp.num[0]] [temp.num[1]] [temp.num[2]] [temp.num[3]]=1;
	}
      }
    }
    front++;
  }
  printf("%d\n", steps);
}
int main(int argc, char *argv[])
{
  int T;
  scanf("%d", &T);
  while(T--){
    int a, b;
    memset(visit, 0, sizeof(visit));
    memset(q, 0, sizeof(q));
    memset(from, 0, sizeof(from));
    memset(to, 0, sizeof(to));
    scanf("%d%d", &a, &b);
    if(a==b) printf ("0\n");
    else{
      from[0]=a/1000; from[1]=a/100%10; from[2]=a/10%10; from[3]=a%10;
      to[0]=b/1000; to[1]=b/100%10; to[2]=b/10%10; to[3]=b%10;
      fun();
    }
  }
  return 0;
}
