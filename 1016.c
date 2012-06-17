#include<stdio.h>
#include<string.h>
int num[22], visit[22];
int n;
int isprime(int t)
{
  int i;
  if(i<2) return 0;
  for(i=2;i*i<=t;i++){
    if(t%i==0) return 0;
  }
  return 1;
}
void dfs(int k)
{
  int i,c=0;
  if(k==n && isprime(num[0]+num[k-1])){
    for(c=0; c<n-1; c++){
      printf("%d ", num[c]);
    }
    printf("%d\n", num[n-1]);
  }
  for(i=2;i<=n;i++){
    if(visit[i]||!isprime(num[k-1]+i)) continue;
    num[k]=i;      
    visit[i]=1;
    dfs(k+1);
    visit[i]=0;			/* 记得要返回状态 */
  }
}
int main()
{
  int i=1;
  while(scanf("%d",&n)!=EOF){
    memset(num, 0, sizeof(num));
    memset(visit, 0, sizeof(visit));
    printf("Case %d:\n", i++);
    num[0]=1;
    visit[1]=1;
    dfs(1);
    printf("\n");
  }
  return 0;
}
