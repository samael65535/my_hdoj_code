#include<stdio.h>
#include<string.h>

int sum;
int cnt[26];
int a[26][26];
/* 2 2 3
   2 3
   3
   先算出小三角形再根据小三角形推出大三角形
 */
void dfs(int n)
{

  int i, j;
  if(n>24) return;
  else{
    for(i=0; i<2; i++){
      a[1][n]=i;
      sum+=i;
      for(j=2; j<=n; j++){
	a[j][n-j+1]=a[j-1][n-j+1]^a[j-1][n-j+2];
	sum+=a[j][n-j+1];
      }
      if(n*(n+1)/2==2*sum){
	cnt[n]++;
      }
      dfs(n+1);
      for(j=2; j<=n; j++){
	sum-=a[j][n-j+1];
      }
      sum-=i;
    }
  }
}
int main()
{
  int n;
  sum=0;
  memset(a, 0, sizeof(a));
  memset(cnt, 0, sizeof(cnt));
  dfs(1);
  while(scanf("%d", &n)!=EOF && n){
    printf ("%d %d\n",n, cnt[n]);

  }
  return 0;
}


