#include<stdio.h>
#include<stdlib.h>
int cmp (const void *a , const void *b )  
{
  return *(int *)a - *(int *)b;
}  
int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  while(n--){
    int i;
    int K[11];
    int t;
    scanf("%d", &t);
    for(i=0; i<t; i++){
      scanf("%d", &K[i]);
    }
    qsort(K, t, sizeof(int), cmp);
    printf ("%d\n", K[1]);
  }
  return 0;
}
