#include <stdio.h>

typedef struct
{
	int num[31];
	int len;
}BigNum; // 要使用大数

BigNum add(BigNum a, BigNum b)
{
	BigNum temp;
	int i;
	temp.num[0] = 0;
	for(i=0;i<a.len||i<b.len;i++)
	{
		if(i<a.len)
			temp.num[i] += a.num[i];
		if(i<b.len)
			temp.num[i] += b.num[i];
		temp.num[i+1] = temp.num[i] / 100000000;
		temp.num[i] = temp.num[i] % 100000000;
	}
	if(temp.num[i]) temp.len = i+1;
	else temp.len = i;
	return temp;
}

void print(BigNum a)
{
	int i;
	printf("%d",a.num[a.len-1]);
	for(i=a.len-2;i>=0;i--)
		printf("%08d",a.num[i]);
	putchar(10);
}

int main()
{
	int i,n;
	BigNum a[1001];
	memset(a,0,sizeof(a));
	a[1].len = 1;
	a[1].num[0] = 1;
	a[2].len = 1;
	a[2].num[0] = 2;
	a[3].len = 1;
	a[3].num[0] = 4;
	a[4].len = 1;
	a[4].num[0] = 7;
	for(i=5;i<1001;i++)
		a[i] = add(a[i-1],add(a[i-2],a[i-4]));
	while(scanf("%d",&n)==1)
	{
		print(a[n]);
	}
}
