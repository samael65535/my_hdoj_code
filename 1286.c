#include<stdio.h>
int main(int argc, char *argv[])
{
  int CN;
  scanf("%d", &CN);
  while(CN--){
    int n, i, new=0, j, f=0;
    short friends[32769]={0};
    scanf("%d", &n);
    for(i=2; i<=n/2; i++){
      if(n%i==0)
	for(j=1; i*j<=n; j++)
	  friends[i*j]=1;
    }
    for(j=1; j<n; j++)
      if(friends[j] == 0) new++;
    printf ("%d\n", new);
  }
  return 0;
}
