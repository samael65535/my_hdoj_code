#include<stdio.h>
int main(int argc, char *argv[])
{
  int A=2,B=2,n;
  while(scanf("%d%d%d", &A, &B, &n)!=EOF && A && B && n){
    int s[52], i;
    s[0]=1;s[1]=1;
    if(n<3)printf ("1\n");
    else{
      for(i=2;i<50;i++){
	s[i]=(A*s[i-1]+B*s[i-2])%7;
      }
      printf ("%d\n", s[(n-1)%49]);
    }
  }
  return 0;
}
