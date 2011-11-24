#include<stdio.h>
#include<stdlib.h>
/* 把w l排序,而且w'<=w l'<=l之后用新的值去比较,因为排过序,所以合适条件的一定在后面 */
struct stick
{
  int l;
  int w;
};
int cmp(const void *a, const void *b)
{
  struct stick *t1 = (struct stick *) a;
  struct stick *t2 = (struct stick *) b;
  if(t1->l != t2->l)    return t1->l - t2->l;
  else    return t1->w - t2->w;
}
int main(int argc, char *argv[])
{
  int a, n;
  scanf("%d", &a);
  while(a--){
    scanf("%d", &n);
    struct stick wooden[5005];
    int i, j, time=0;
    int w, l;
    struct stick t;
    for(i=0; i<n; i++){
      scanf("%d%d", &l, &w);
      wooden[i].l = l;
      wooden[i].w = w;
    }
    qsort(wooden, n, sizeof(wooden[0]), cmp);
    for(i=0; i<n; i++){
      if(wooden[i].l==0 && wooden[i].w==0) continue;
      t = wooden[i];
      wooden[i].l = wooden[i].w = 0;
      for(j=i+1; j<n; j++){
	if(wooden[j].l>=t.l && wooden[j].w>=t.w){
	  t = wooden[j];
	  wooden[j].l = wooden[j].w = 0;
	}
      }
      time++;
    }
    printf ("%d\n", time);
  }
  return 0;
}
