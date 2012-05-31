#include<stdio.h>
#include<math.h>
long long num[1003];
int main(int argc, char *argv[])
{
  int n;
  num[1]=1;num[2]=2;
  for(n=3; n<1001; n++){
    num[n] = pow(2,n-1)-num[n-1];
  }
  while(scanf("%d", &n) != EOF){
    if(n==1) printf ("3\n");
    else printf ("%I64d\n", num[n]*3);
  }
  return 0;
}

