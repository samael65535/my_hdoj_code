/* 贪心方法 */
#include<stdio.h>
#include<stdlib.h>
typedef struct{
  int p, h;
}Rice;
int cmp(const void *a, const void *b)
{
  Rice *x=(Rice *)a;
  Rice *y=(Rice *)b;
  if(x->p == y->p) return x->h - y->h;
  return x->p - y->p;
}
int main(int argc, char *argv[])
{
  int C;
  scanf("%d", &C);
  while(C--){
    int n, m;
    while(scanf("%d%d", &n, &m)!=EOF){
      int i, j;
      float k=0;
      Rice r[1005];
      for(i=0; i<m; i++){
	scanf("%d%d", &r[i].p, &r[i].h);
      }
      qsort(r, m,sizeof(r[0]), cmp);
      /* for(i=0; i<m; i++){ */
      /* 	printf("%d  %d\n", r[i].p, r[i].h); */
      /* } */
      for(i=0; i<m; i++){
      	if(n-r[i].p*r[i].h>0){
      	  k+=r[i].h;
      	  n=n-r[i].p*r[i].h;
      	}
      	else{
      	  k+=((float)n/r[i].p);
      	  break;
      	}
      }
      printf ("%.2f\n",k);
    }
  }
  return 0;
}
