#include<stdio.h>
int main(int argc, char *argv[])
{
  int n;
  while(scanf("%d", &n)!=EOF){
    char *score="EEEEEEDCBAA";
    if(n<=100 && n>=0)
      printf ("%c\n",score[n/10]);
    else
      printf ("Score is error!\n");
  }
  return 0;
}
