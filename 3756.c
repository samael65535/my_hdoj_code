#include<stdio.h>
#include<math.h>
#define PI acos(-1.0)
double eps=1e-9;
typedef struct
{
  double z, r;
}point;
point p[10001];
int main(int argc, char *argv[])
{
  int T;
  scanf("%d", &T);
  while(T--){
    int i, max1=0, max2=0, n;
    double x, y, z;
    scanf("%d", &n);
    for(i=0; i<n; i++){
      scanf("%lf%lf%lf", &x, &y, &z);
      p[i].r=sqrt(x*x+y*y);
      p[i].z=z;
      if(p[i].r>p[max1].r) max1=i;
      if(p[i].z>p[max2].z) max2=i;
    }

    double l=0, r=1002, mid, mmid, d;
    z=p[max1].z; d=p[max1].r;
    if(p[max1].r==p[max2].r) {
      l=0;
      z=p[max2].z;
    }else {
      l=(p[max2].z-p[max1].z)/(p[max1].r-p[max2].r);
    }
    while(1){
      mid=(2*l+r)/3;
      mmid=(l+r*2)/3;
      if(mmid-mid<eps) break;
      double vl = (z+d*mid)*(z+d*mid)*(z+d*mid)/mid/mid;
      double vr = (z+d*mmid)*(z+d*mmid)*(z+d*mmid)/mmid/mmid;
      /* if((z+d*mid)*(z+d*mid)*(z+d*mid)/mid/mid<(z+d*mmid)*(z+d*mmid)*(z+d*mmid)/mmid/mmid) */
      if(vl<vr)
    	r=mmid;
      else
	l=mid;
    }
    printf ("%.3lf %.3lf\n", (z+d*mid), (z+d*mid)/mid);
  }
  return 0;
}
