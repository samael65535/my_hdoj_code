#include<stdio.h>
#include<math.h>
long long RPG[51];
int main(int argc, char *argv[])
{
  int n;
  RPG[1]=0;
  for(n=2; n<51; n++){
    RPG[n]=pow(2, n-1)-RPG[n-1];
  }
  while(scanf("%d", &n)!=EOF){
    if(n==1) printf ("3\n");
    else printf ("%I64d\n", RPG[n]*3);
  }
  return 0;
}

