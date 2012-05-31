#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXN 10005
#define MAXSIZE 100000
double cable[MAXN];
double eps=1e-3;
int main(int argc, char *argv[])
{
  int N, K;
  while(scanf("%d%d", &N, &K) != EOF && N && K){
    int i, sum, flag=0;
    double l=0, r, mid, maxl=-1;
    memset(cable,0, sizeof(cable));
    for(i=0; i<N; i++){
      scanf("%lf", &cable[i]);
      if(maxl<cable[i]) maxl=cable[i];
    }
    r=maxl;
    maxl=-1;
    while(fabs(l-r)>eps){
      mid=(l+r)/2;
      sum=0;
      for(i=0; i<N; i++){
	sum+=(cable[i]/mid);
      }
      if(sum<K) r=mid;
      else l=mid;
      if(sum==K && maxl<mid){flag=1; maxl=mid;}
    }

    if(!flag) printf ("0.0\n");
    else printf("%.2f\n", maxl);
  }
  return 0;
}
