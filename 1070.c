#include<stdio.h>
#include<stdlib.h>
typedef struct {
  char s[100];
  int P;
  int V;
  float c;
}milk;
int cmp(const void *a, const void *b)
{
  milk *x=(milk *a);
  milk *y=(milk *b);
  if(x->P-y->P==0) return x->V-y->V;
  else x->P-y->P;
}
int main(int argc, char *argv[])
{
  int T;
  scanf("%d", &T);
  while(T--){
    int n, i;
    milk a[100];
    scanf("%d", &n);
    for(i=0; i<n; i++){
      scanf("%s%d%d", a[i].s, &a[i].P, &a[i].V);
      if(a[i].V>=1200) a[i].V=1200;
    }
  }
  return 0;
}

