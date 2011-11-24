#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* 注意开头是 5的情况 */
int cmp (const void *a , const void *b )  
{
  return *(int *)a - *(int *)b;
}
int main(int argc, char *argv[])
{
  char *num = (char *)malloc(sizeof(char)*10001);
  while(scanf("%s", num) != EOF){
    int i, j=0, t=0, a, f=0;
    long long k[10001];
    for(i=0; num[i] != '\0'; i++){
      if(num[i] == '5')continue;
      if(num[i] != '5'){
	a = num[i] - 48;
	t = t * 10 + a;
      }
      if(num[i+1] == '5'){	/* 应该是成对出现的 */
	k[j++]=t;
	t = 0;
      }
    }
    if(num[i-1] != '5'){
      k[j++] = t;
    }
    qsort(k, j, sizeof(long long), cmp);    
    for(i=0; i<j-1; i++){
      printf ("%lld ", k[i]);
    }
    printf ("%lld\n", k[i]);
  }
  return 0;
}
