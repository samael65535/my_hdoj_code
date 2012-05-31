#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int board[11], sum, hehe[11];
int check(int k)
{
  int i;
  for(i=1; i<k; i++){
    if(abs(i-k)== abs(board[i]-board[k]) ||
       board[i]==board[k])	/* 相差的行数等于相差的列数就是斜线 */
      return 0;
  }
  return 1;
}
void solve(int a)
{
  int n=a;
  board[1]=0;
  int k=1;
  sum=0;
  while(k>0){
    board[k]++;
    while(board[k]<=n && !check(k)) board[k]+=1;
    if(board[k]<=n){
      if(k==n){
	sum++;
      }else{
	k++;
	board[k]=0;
      }
    }else {
      k--;
    }
  }
  hehe[a]=sum;
}
int main(int argc, char *argv[])
{
  int i;
  for(i=1; i<=10; i++){
    solve(i);
    memset(board, 0, sizeof(board));
  }
  int a;
  while(scanf("%d", &a)!=EOF && a){
    printf ("%d\n", hehe[a]);
  }
  return 0;
}
