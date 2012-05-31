#include<stdio.h>
#include<stdlib.h>
/* 1。如果你最快的马比他最快的马快，那么用你最快的马跟他最快的马比。
2。如果你最慢的马比他最慢的马快，那么用你最慢的马跟他最慢的马比。
3。如果不符合上面2种情况，用你最慢的马跟他最快的马比。
 */
int cmp(const void *a, const void *b)
{
  return *(int *)a-*(int *)b;
}
int main(int argc, char *argv[])
{
  int n, a[1005], b[1005];
  while(scanf("%d", &n)!=EOF && n){
    int i, j, sum=0, l=0, ts, te, ks, ke;
    for(i=0; i<n; i++){
      scanf("%d", &a[i]);
    }
    for(i=0; i<n; i++){
      scanf("%d", &b[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    qsort(b, n, sizeof(int), cmp);
    ts=ks=0;
    te=ke=n-1;
    while(ts<=te){
      if(a[te]>b[ke]){	sum++;	te--; ke--;}
      else if(a[ts]>b[ks]){sum++; ts++; ks++;}
      else if(a[ts]<b[ke]){sum--; ts++; ke--;}
      else {te--; ks++;}
    }
    printf ("%d\n", sum*200);
  }
  return 0;
}
