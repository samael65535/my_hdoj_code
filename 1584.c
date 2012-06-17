#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int card[11];
int visit[11];
int ans;
void dfs(int cur, int temp)
{
  if(temp>=ans) return;
  if(cur==9){
    ans = temp;
    return;
  }
  int i;
  for(i=1; i<10;i++){
    if(!visit[i]){
      int k;
      for(k=i+1; k<=10; k++){
	if(!visit[k]){
	  visit[i]=1;
	  dfs(cur+1, temp+abs(card[k]-card[i]));
	  break;
	}
      }
      visit[i]=0;
    }
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  while(n--){
    int i, s;
    for(i=1; i<=10; i++){
      scanf("%d", &s);
      card[s]=i;
    }
    memset(visit, 0, sizeof(visit));
    ans=100000;
    dfs(0,0);
    printf("%d\n", ans);
  }
}
