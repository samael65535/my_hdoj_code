#include<stdio.h>
#define MAX 1000001
/* 向后搜索更新最大值,最大质因数 */
int num[MAX];    		/* 要声明在外面要不会溢出 */
int main(int argc, char *argv[])
{
  int i, j;
  int n, k=0;
  for(i=1; i < MAX; i++) num[i] = 0;
  for(i=2; i < MAX; i++){
    if(num[i]==0){
      k++;
      for(j = i; j < MAX; j+=i) num[j] = k;
    }
  }
  while(scanf("%d", &n) != EOF){
    printf ("%d\n", num[n]);
  }
  return 0;
}
