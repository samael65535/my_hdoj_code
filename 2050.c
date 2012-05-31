#include <stdio.h>
int main(int argc, char *argv[])
{
  int i;
  scanf("%d", &i);
  while(i--){
    int n;
    scanf("%d", &n);
    int max=1+n*(2*n+1)-2*n;
    printf ("%d\n", max);
  }
  return 0;
}

