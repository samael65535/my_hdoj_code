#include<stdio.h>
#include<string.h>
int num[22], visit[22];
void show(int c)
{
  int i, flag=1;
  memset(visit, 0, sizeof(visit));
  for(i=1; i<=c; i++){
    if(visit[num[i]]==1) return;
    else visit[num[i]]=1;
  }
  if(flag){
    for(i=1; i<c; i++){
      printf("%d ", num[i]);
    }
    printf ("%d\n",num[i]);
  }
}
int isprime(int n)
{
  int i;
  if(i<2) return 0;
  for(i=2;i*i<=n;i++){
    if(n%i==0) return 0;
  }
  return 1;
}
int check(int k, int n)
{
  int i;
  for(i=1; i<k; i++){
    if(!isprime(num[i]+num[i+1])) return 0;
  }
  if(k==n && !isprime(num[1]+num[n])) return 0;
  return 1;
}
void fun(int n)
{
  int count=0, i, k=2;
  num[1]=1;
  while(k>1){
    num[k]++;
    while((num[k]<=n)&&!(check(k, n))) num[k]+=1;
    if(num[k]<=n){
      if(k==n){
	show(n);
      }else{
	k++;
	num[k]=1;
      }
    }
    else
      k--;
  }
  printf ("\n");
}
int main()
{
  int n, i=1;
  while(scanf("%d",&n)!=EOF){
    printf ("Case %d:\n", i++);
    memset(num, 0, sizeof(num));
    memset(visit, 0, sizeof(visit));
    fun(n);
  }
  return 0;
}
