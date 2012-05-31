#include<stdio.h>
#define MAX 100
int main(int argc, char *argv[])
{
  int c;
  scanf("%d", &c);
  while(c--){
    int n, i, j, a, b;
    scanf("%d", &n);
    int num[MAX][MAX];
    for(i=0; i<n; i++){
      for(j=0; j<=i; j++){
	scanf("%d", &num[i][j]);
      }
    }
    for(i=n-2; i>-1; i--){
      for(j=0; j<=i; j++){
	a=num[i+1][j] + num[i][j];
	b=num[i][j] + num[i+1][j+1];
	num[i][j]=a>b?a:b;
      }
    }
    printf ("%d\n", num[0][0]);
  }
  return 0;
}
