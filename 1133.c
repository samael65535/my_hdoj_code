#include<stdio.h>
int main(int argc, char *argv[])
{
  int m, n, i=1;
  while(scanf("%d%d", &m, &n)!=EOF && m && n){
    printf ("Test #%d:\n%d\n",i++,); 
 }
  return 0;
}

