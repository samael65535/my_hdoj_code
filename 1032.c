#include<stdio.h>
int len[1000005];
int main(int argc, char *argv[])
{
  int i,j;
  while(scanf("%d%d", &i, &j)!=EOF){
    int max=1, count=1, a, b;
    a=i<=j?i:j;
    b=j>=i?j:i;
    for(; a<=b; a++){
      int n=a;
      if(len[a]!=0){count=len[a];}
      else{
	while(n!=1){
	  if(n%2) n=3*n+1;
	  else n=n/2;
	  count++;
	}
	len[a] = count;
      }
      max=count>max?count:max;
      count=1;
    }
    printf ("%d %d %d\n", i, j, max);
  }

  return 0;
}
