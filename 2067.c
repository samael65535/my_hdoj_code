#include<stdio.h>

int main(int argc, char *argv[])
{
  long long a[37][37];
  int n, i, j;
  for(i=0;i<37;i++){
    a[1][i]=1;
    a[i][1]=1;
  }
  for(i=2;i<37;i++){
    for(j=2;j<37;j++){
      if(i == j)
	a[i][j] = a[i-1][j];
      else
	a[i][j]=a[i-1][j]+a[i][j-1];
    }
  }
  i=1;
  while(scanf("%d", &n) != EOF && n != -1){
    printf ("%d %d %I64d\n", i++, n,a[n+1][n+1]*2);
  }
  return 0;
}
