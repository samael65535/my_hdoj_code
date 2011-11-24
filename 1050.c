#include<stdio.h>
/* 移桌子,注意奇偶数,可以用数组直接做,一直累加,找出最大的花费 */
int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  while(n--){
    int T[402]={0};
    int i, k, temp;
    int s, t, j, max;
    scanf("%d", &j);
    for(i=0; i<j; i++){
      scanf("%d%d", &s, &t);
      if(s>t){
	temp=t;
	t = s;
	s = temp;
      }
      if(t%2==1) t+=1;
      for(k=s; k<=t; k++){
	T[k] += 10;
      }
    }
    max = T[0];
    for(i=1; i<401; i++){
      if(max < T[i]) max = T[i];
    }
    printf ("%d\n", max);
  }
  return 0;
}
