#include<stdio.h>
#include<stdlib.h>
/* this code is wrong */
int cmp(const void *a, const void *b)
{
  return *(int *)a-*(int *)b;
}
int main(int argc, char *argv[])
{
  int n;
  while(scanf("%d", &n) != EOF){  
    int num[100000];
    int i, j, count=0;
    for(i=0; i<n; i++){
      scanf("%d", &num[i]);
    }

    qsort(num, n, sizeof(num[0]), cmp);
    for(i=0; i<n; i++){
      printf ("%d",num[i]);
    }
    printf ("\n");
    for(i=0; i<n; i++){
      if(num[i]==0) continue;
      count++;
      for(j=i; j<n; j++){	/* 不能这样做比如44444就不行 */
	if(num[j]%num[i] == 0 && num[j]!=num[i] && num[j]) num[j]=0;
      }
    }
    printf ("%d\n", count);
  }
  return 0;
}

