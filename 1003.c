#include<stdio.h>
#define MAX 100005
int main(int argc, char *argv[])
{
  int num[MAX] = {0};
  int sum[MAX] = {0};
  int n, k=1, t=0;
  int start, end, max, flag=0;
  scanf("%d", &t);
  while(t--){
    if(flag == 0)
      flag = 1;
    else
      printf ("\n");
    scanf("%d", &n);
    for(start = 1; start <= n; start++)
      scanf("%d", &num[start]);
    sum[1] = num[1];
    max = num[1];
    end = 1;
    for(start = 2;start <= n; start++){
      if(sum[start-1]<0){	/* 负数就抛弃,只会减弱 */
	sum[start] = num[start];
      }
      else{
	sum[start] = num[start] + sum[start-1];
      }
        if(max<sum[start]){
	max = sum[start];
	end = start;
      }
    }
    if(max < 0) start = end - 1;
    else{
      for(start = end; start>=1; start--){
	if(sum[start]<0) break;
      }
    }
    printf ("Case %d:\n",k++);
    printf ("%d %d %d\n",max, start+1, end);
    for(start = 1; start <= n; start++){
      printf ("%d %d %d\n",start, num[start], sum[start]);
    }

  }
  return 0 ;
}
