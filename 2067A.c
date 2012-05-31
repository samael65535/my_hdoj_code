#include <stdio.h>
#include <string.h>
#define MAX 40
int main()
{
  long long flag[MAX][MAX];
  for(int i=0; i<=35; i++)
    flag[0][i] = 1;
  for(int i=1; i<=35; i++)
    for(int j=1; j<=35; j++)
      if(i == j)
	flag[i][j] = 0;
      else
	flag[i][j] = flag[i-1][j] + flag[i][j-1];
for (int i = 0; i < 15; ++i)
  {
    for (int j = 0; j < 15; ++j)
      {
	printf ("%lld\t", flag[i][j]);
      }
printf ("\n");
  }

  /* for(int i=1, n; scanf("%d", &n), n!=-1; i++) */
  /*   printf("%d %d %I64d\n", i, n, flag[n][n] * 2);//fuck!%lld改成I64d就过了～～杭电怎么回事？我记得有的题用lld可以过的啊～～～ */
  return 0;
}
