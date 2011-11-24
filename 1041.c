#include<stdio.h>
int main(int argc, char *argv[])
{
  int a[1002][500] = {0};
  int n;
  int i,j, flag=0;
  a[0][0] = 0;
  a[1][0] = 0;
  a[2][0] = 1;
  for(i = 3; i<1001; i++){
    for(n = 0; n < 500; n++){
      j = a[i-1][n]+2*a[i-2][n]+a[i][n];
      if(j>9){
	a[i][n+1] = j/10;
	a[i][n] = j%10;
      }else{
	a[i][n] = j;
      }
    }
  }
  while(scanf("%d", &n) != EOF){
    if(n==1 || n==0){
      printf ("0\n");
      continue;
    }
    for(i=499; i>=0; i--){
      if(a[n][i] != 0 || flag == 1){
	flag = 1;
	printf ("%d", a[n][i]);
      }
    }
    printf ("\n");
    flag = 0;
  }
  return 0;
}
