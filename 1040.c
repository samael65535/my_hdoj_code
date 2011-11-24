#include<stdio.h>
#include<stdlib.h>
int cmp ( const void *a , const void *b )
{
  return *(int *)a - *(int *)b;
}
int main(int argc, char *argv[])
{
  int n, i, s;
  int num[1001];
  scanf("%d", &n);
  while(n--){
    scanf("%d", &s);
    for(i=0; i<s; i++){
      scanf("%d", &num[i]);
    }
    qsort(num,s,sizeof(num[0]),cmp);
    for(i=0; i<s-1; i++){
      printf("%d ", num[i]);
    }
    printf("%d\n", num[i]);
  }
  return 0;
}
