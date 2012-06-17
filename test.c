#include<stdio.h>

int main(int argc, char *argv[])
{
  int n, m ,t;
  while(scanf("%d%d%d", &n, &m, &t)!=EOF && (n || m || t)){
    printf("%d %d %d\n", n, m, t);
  }

  return 0;
}
