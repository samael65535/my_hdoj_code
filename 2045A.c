#include<stdio.h>
int main()
{
	long long a[51];
	int i,n;
	a[1]=3;
	a[2]=6;
	a[3]=6;
	for(i=4;i<=50;i++)
		a[i]=a[i-1]+2*a[i-2];
	while(scanf("%d",&n)!=EOF)
	{
		printf("%I64d\n",a[n]);
	}
	return 0;
}
