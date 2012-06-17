#include<stdio.h>
#include<string.h>
int n;
int sum, num1, num0;
int a[25][25];
int t;
int isOK(int x, int y, int z)
{
  if(y>0){
    if(z){
      if(a[y-1][x+1]!= a[y-1][x]) return 0;
    }else{
      if(a[y-1][x+1] == a[y-1][x]) return 0;
    }
  }
  return 1;
}
void dfs(int x, int y)
{
  if(t/2<num1 || t/2<num0){
    return ;
  }
  if(y==n){
    if(num1==num0){
      sum++;
    }
    return;
  }else{
    a[y][x]=1;
    num1++;
    if(t/2>=num1){
      if(isOK(x, y, 1)){
	if(x+1<n-y) dfs(x+1, y);
	else dfs(0, y+1);
      }
    }      
    num1--;
    a[y][x]=0;
    num0++;
    if(t/2>=num0){
      if(isOK(x, y, 0)){
	if(x+1<n-y) dfs(x+1, y);
	else dfs(0, y+1);
      }
    }
    num0--;
    a[y][x]=-1;
    return ;
  }
}
int main()
{
  while(scanf("%d", &n)!=EOF && n){
    sum=num1=num0=0;
    memset(a, -1, sizeof(a));
    t=(1+n)*n/2;
    if(t%2==1){
      printf ("%d %d\n",n, sum);
    }else{
      dfs(0, 0);
      printf ("%d %d\n",n, sum);
    }
  }
  return 0;
}


