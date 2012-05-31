#include<stdio.h>
#include<string.h>
int max(int x, int y)
{
  return x>y?x:y;
}
int main(int argc, char *argv[])
{
  int c;
  scanf("%d", &c);
  while(c--){
    int p[105], h[105], c[105], pig[105];
    int n, m, i, j, k, money=0;
    scanf("%d%d", &n, &m);
    memset(pig, 0, sizeof(pig));
    p[0]=h[0]=c[0]=0;
    for(i=1; i<=m; i++){
      scanf("%d%d%d", &p[i], &h[i], &c[i]);
    }
    for(i=1; i<=m; i++){
      for(j=1; j<=c[i]; j++){
	for(k=n; k>=p[i]; k--){
	  pig[k]=max(pig[k-p[i]]+h[i], pig[k]);
	}
      }
    }
    printf ("%d\n",pig[n]);
  }
  return 0;
}
