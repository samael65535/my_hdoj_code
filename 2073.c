#include<stdio.h>
int main(int argc, char *argv[])
{
  int n, b, t;
  int i, min, count=0;
  int k[102][2];
  while(scanf("%d", &n) != EOF && n){
    b = 0;
    count = 0;
    for(i=0; i<n; i++){
      scanf("%d%d", &k[i][0], &k[i][1]);
    }
    while(1){
      min = 1000;
      for(i = 0; i<n; i++){
	if(b<=k[i][0] && k[i][1]-b<min){ /* 找大于上一个终点与下一个终点最近的距离,把最近的终点当成起点 */
	  min = k[i][1] - b;
	  t = k[i][1];
	}
      }
      if(b == t) break;  	/* 如果上个起点与终点没变说明已经到头 */
      else b = t;
      count++;
    }
    printf ("%d\n",count);
  }
  return 0;
}
