#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
  return *(char *)a-*(char *)b;
}
int main(int argc, char *argv[])
{
  char c[3];
  while(scanf("%s", c)!=EOF){
    int i;
    qsort(c, 3, sizeof(c[0]), cmp);
    for(i=0; i<2; i++)
      printf("%c ", c[i]);
    printf ("%c\n",c[i]);
  }
  return 0;
}
