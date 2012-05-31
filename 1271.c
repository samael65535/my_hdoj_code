#include<stdio.h>
#include<math.h>
/* 12
输出： 11
就一个11. */
int main(int argc, char *argv[])
{
  int n;
  while(scanf("%d", &n) != EOF && n){
    int tmp=n, flag=0;
    int i, j, k, num, N, s;
    int A, B, C;
    for(num=0; tmp=tmp/10; num++);

    for(s=1; s<n; s*=10){
      for(i=0; i<=num; i++){
	/* C = s/(int)pow(10, i)%10; */
	A = s % (int)pow(10, i);
	B = s / (int)pow(10, i+1);
	N = B*pow(10,i)+A;
	if(s+N != k){
	  k=s+N;
	  if(k==n)
	    printf ("%d\n", s);
	}
      }
    }
  }
  return 0;
}
