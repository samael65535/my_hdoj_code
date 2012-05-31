#include<stdio.h>
#include<string.h>
#define MIN -999999999
int main(int argc, char *argv[])
{
  int C;
  scanf("%d", &C);
  while(C--){
    int n, m, i, j;
    int chess[23][1005]={0};
    int f[23][1005]={0};
    int max=0, sumr=0, sumu=0, sumrn=0;
    scanf("%d%d", &n, &m);
    for(i=1; i<=n; i++)
      for(j=1; j<=m; j++)
	scanf("%d", &chess[i][j]);
    printf("%d\t", f[1][1]);
    f[1][1]=chess[1][1];
    for(i=0;i<=m;i++)
      {
	f[0][i] = MIN;
      }

    for(i=2; i<=n; i++) f[i][1] = f[i-1][1]+chess[i][1];
    for(i=1; i<=n; i++){
      printf("%d\t", f[i][1]);
      for(j=2; j<=m; j++){
	int k;
	max=MIN;
	for(k=1; k<j; k++){
	  if((j%k==0) && (max<f[i][k])) max=f[i][k];
        }
	max = max < f[i-1][j] ? f[i-1][j] : max;
	max = max < f[i][j-1] ? f[i][j-1] : max;
	f[i][j]=max+chess[i][j];
	printf("%d\t", f[i][j]);
      }
      printf("\n");
    }
    printf("%d\n", f[n][m]);
  }
  return 0;
}
