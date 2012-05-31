#include<stdio.h>
#include<string.h>
#define MAX 1002
int main(int argc, char *argv[])
{
  int n;
  while(scanf("%d", &n) != EOF && n){
    int i, max=0, p=0, j, count=0, temp=0;
    int chess[MAX], sum[MAX];
    memset(chess, 0, sizeof(chess));
    memset(sum, 0, sizeof(sum));
    for(i=0; i<n; i++){
      scanf("%d", &chess[i]);
      /* printf ("%d\t",chess[i] ); */
    }
    /* printf ("\n"); */
    sum[0]=chess[0];
    for(i=0; i<n; i++){
      for(j=i-1; j>-1; j--){
	if(chess[j]<chess[i]){
	  if(max<sum[j]) max=sum[j];
	}
      }
      sum[i]=max+chess[i];
      max=0;
    }
    for(i=0; i<n; i++){
      if(max<sum[i]) max=sum[i];
      /* printf ("%d\t", sum[i]); */
    }
    printf ("%d\n", max);

  }
  return 0;
}

