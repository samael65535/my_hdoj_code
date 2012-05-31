#include<stdio.h>
#include<stdlib.h>
typedef struct{
  int x, y, z, area;
} cube;
int cmp(const void *a, const void *b)
{
  cube *c=(cube *)a;
  cube *d=(cube *)b;
  return (c->area)-(d->area);
}
int main(int argc, char *argv[])
{
  int n;
  int cas=0;
  while(scanf("%d", &n)!= EOF && n){
    cube c[95];
    int high[95];
    int i,j,max,x,y,z;
    cas++;
    n*=3;
    for(i=0; i<n; i++){
      scanf("%d%d%d", &x, &y, &z);
      c[i].x=x; c[i].y=y; c[i].z=z; c[i].area=c[i].x*c[i].y;i++;
      c[i].x=y; c[i].y=z; c[i].z=x; c[i].area=c[i].x*c[i].y;i++;
      c[i].x=z; c[i].y=x; c[i].z=y; c[i].area=c[i].x*c[i].y;
    }
    qsort(c, n, sizeof(cube), cmp);
    for(i=0; i<n; i++) high[i] = c[i].z;
    for(i=0; i<n; i++){
      max=0;
      /* printf ("a%d  %d\n", i ,c[i].area); */
      for(j=0; j<i; j++){
	if(((c[i].x>c[j].x && c[i].y>c[j].y) ||
	    (c[i].x>c[j].y && c[i].y>c[j].x)) &&
	   max<high[j])
	  max=high[j];
      }
      high[i]+=max;
      /* printf ("%d\t", high[i]); */
    }
    for(i=max=0; i<n; i++){
      if(max<high[i]) max=high[i];
      /* printf ("%d\t", high[i]); */
    }
    printf ("Case %d: maximum height = %d\n", cas, max);
  }
  return 0;
}
