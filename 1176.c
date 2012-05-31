#include<stdio.h>
#include<string.h>
#define MAX 100002
int t[11][MAX];
int max(int x, int y)
{
  return x>y?x:y;
}
int main(int argc, char *argv[])
{
  int n;
  while(scanf("%d", &n)!=EOF && n){
    int i, j, x, time, m=0;
    memset(t, 0, sizeof(t));
    for(i=1;i<=n;i++){
      scanf("%d%d", &x, &time);
      t[x][time]+=1;
      if(m<time) m=time;	/* 注意要考虑time的最大值 */
    }
    for(i=m; i>0; i--){
      for(j=0; j<11; j++){
	if(j==0)
	  t[0][i-1]+=max(t[0][i],t[1][i]);
	else if(j==10)
	  t[10][i-1]+=max(t[10][i], t[9][i]);
	else
	  t[j][i-1]+=max(max(t[j-1][i],t[j][i]), max(t[j][i], t[j+1][i]));
      }
    }
    printf ("%d\n",t[5][0]);
    /* for(i=0; i<11; i++){ */
    /*   for(j=0; j<=time; j++) */
    /* 	printf ("%d\t", t[i][j]); */
    /*   printf ("\n"); */
    /* } */
  }
  return 0;
}
