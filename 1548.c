/* 电梯,最短时间 */
#include<stdio.h>
#include<string.h>
typedef struct{
  int now; 
  int down;
  int up;
  int step;
}F;

F q[5000], fl[205];
int visit[205];
void fun(int N, int A, int B)
{
  int front=0, rear=0, steps=1000000;
  F temp;
  q[rear++]=fl[A];
  while(front<=rear){
    temp = q[front];
    if(temp.now==B){
      steps=temp.step<steps?temp.step:steps;
    }
    if(temp.down>0 && !visit[temp.now]){
      rear++;
      visit[temp.now]=1;
      q[rear]=fl[temp.down];
      /* q[rear].step=q[rear].step<temp.step+1?q[rear].step:temp.step+1; */
      q[rear].step+=temp.step+1; /* 所花时间 */
    }
    if(temp.up>0 && !visit[temp.up]){
      rear++;
      visit[temp.now]=1;
      q[rear]=fl[temp.up];
      q[rear].step+=temp.step+1;
      /* q[rear].step=q[rear].step<temp.step+1?q[rear].step:temp.step+1; */
    }
    front++;
  }
  printf("%d\n",steps==1000000?-1:steps);
}
int main(int argc, char *argv[])
{
  int N, A, B;
  while(scanf("%d%d%d", &N, &A, &B)!=EOF && N){
    int i, k;
    memset(visit, 0, sizeof(visit));
    for(i=1; i<=N; i++){
      scanf("%d", &k);
      fl[i].now=i;
      fl[i].up=i+k>N?0:i+k;
      fl[i].down=i-k<1?0:i-k;
      fl[i].step=0;
      /* printf ("%d %d %d %d\n", fl[i].now, fl[i].up, fl[i].down, B); */
    }
    fun(N, A, B);
    k=0;
  }

  return 0;
}

