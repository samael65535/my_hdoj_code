#include<stdio.h>
#include<math.h>
double PI=3.1415926;
double eps=1e-9;
double x, y,l,d;
double cal(double i)
{
	return -(x-l*sin(i)-d/cos(i))/tan(i);
}
int fun()
{	double i, left=0, right=PI/2, lmid, rmid;
	while(fabs(right-left)<eps){
		lmid=(2.0*left+right)/3;
		rmid=(left+2.0*right)/3;
		if(cal(lmid)<cal(rmid))	
			right=rmid;
		else 
			left=lmid;
	}
	if(fabs(cal(right))<=y)	return 1;
	else	return 0;
}
int main()
{	
	while(scanf("%lf%lf%lf%lf",&x,&y,&l,&d)!=EOF){
		printf("%s\n",fun()?"yes":"no");
	}
	return 0;
}