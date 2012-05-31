#include<stdio.h>
#include<string.h>
#define N 504
int main()
{
  char x[N];
  char y[N];
  while(scanf("%s%s",x,y)!=EOF){
    int num[N+1][N+1]={0};
    int m=strlen(x);
    int n=strlen(y);
    int i,j;
    int max;
    for(i=1; i<=m; i++){
      for(j=1; j<=n; j++){
	if(x[i-1]==y[j-1]){
	  num[i][j]=num[i-1][j-1]+1;
	}
	else
	  num[i][j]=num[i][j-1]>num[i-1][j]?num[i][j-1]:num[i-1][j];
      }
    }     
    printf("%d\n",num[i-1][j-1]);
  }
  return 0;
}
