#include<stdio.h>
#include<math.h>
double x,y,l,w;
double cal(double i)
{
return -(x-l*sin(i)-w/cos(i))/tan(i);
}
int main()
{

  while(scanf("%lf%lf%lf%lf",&x,&y,&l,&w)!=EOF)
    {
      double i,pi=acos(-1.0),l,r,mid,mmid;
      l=0;
      r=pi/2;
      while(r-l>0.0001)
	{
	  mid=(l+r)/2;
	  mmid=(l+mid)/2;
	  if(cal(mid)>cal(mmid))
	    {
	      l=mmid;
	    }
	  else
	    r=mid;
	}
      if(cal(l)<y)
	printf("yes\n");
      else
	printf("no\n");
    }
  return 0;
}
