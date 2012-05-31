#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
  int C;
  scanf("%d", &C);
  while(C--){
    int n, m, i, j;
    int chess[23][1005]={0};
    int max=0, sumr=0, sumu=0, sumrn=0;
    scanf("%d%d", &n, &m);
    for(i=0; i<n; i++)
      for(j=0; j<m; j++)
	scanf("%d", &chess[i][j]);
    /* printf("%d\t", chess[0][0]); */
    for(i=1; i<n; i++) chess[i][0]+=chess[i-1][0];
    for(i=0; i<n; i++){
      for(j=1; j<m; j++){
	int k;
	sumr=sumrn=sumu=max=-999999999;
	if(i>0)sumu = chess[i-1][j]+chess[i][j];
	sumr = chess[i][j-1]+chess[i][j];
	for(k=1; k<1+j; k++){
	  if((j+1)%k==0){
	    sumrn = chess[i][k-1]+chess[i][j];
	    /* printf("%d\n", sumrn); */
	    if(sumrn>max) max=sumrn;
	  }
	}
	if(max<sumr) max=sumr;
	if(max<sumu) max=sumu;
	chess[i][j]= max;
	/* printf("%d\t", chess[i][j]); */
      }
      /* printf("\n"); */
    }
    printf("%d\n", chess[n-1][m-1]);
  }
  return 0;
}
