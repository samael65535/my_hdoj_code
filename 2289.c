#include<stdio.h>
#include<math.h>
#define PI acos(-1.0)		/* PI要这样取 */
double esp=1e-9;
double vol(double r, double R, double x, double h)
{
  double r1=(R-r)*x/h+r;
  return (r1*r1+r1*r+r*r)*PI*x/3;
}
int main(int argc, char *argv[])
{
  int T;
  scanf("%d", &T);
  while(T--){
    double r, R, H, V;
    scanf("%lf%lf%lf%lf", &r, &R, &H, &V);
    double mid, left=0 ,right=H;
    while(fabs(left-right)>esp){
      mid=(left+right)/2;
      if(vol(r,R,mid,H)>V) right=mid;
      else left=mid;
    }
    printf ("%.6lf\n", mid);
  }
  return 0;
}
