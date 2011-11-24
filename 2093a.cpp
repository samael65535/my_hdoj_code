#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	char name[11];
	int time,solved;
};
node stu[10000];
int cmp(node a,node b)
{
	if(a.solved==b.solved)
	{
		if(a.time==b.time)
			return strcmp(a.name,b.name)<0;
		return a.time<b.time;
	}
	return a.solved>b.solved;
}
int main()
{
  int problem,m,a,i,j;
  //freopen("00.txt","r",stdin);
  //freopen("11.txt","w",stdout);
  scanf("%d%d",&problem,&m);
  i=0;
  while(scanf("%s",stu[i].name)!=EOF)
    {
      stu[i].time=stu[i].solved=0;
      for(j=0;j<problem;j++)
	{
	  scanf("%d",&a);
	  if(a<=0) continue;
	  stu[i].solved++;
	  stu[i].time+=a;
	  if(getchar()=='(')
	    scanf("%d",&a),
	      stu[i].time+=a*m,
	      getchar();
	}
      i++;
    }
  sort(stu,stu+i,cmp);
  for(j=0;j<i;j++)
    printf("%-10s %2d %4d\n",stu[j].name,stu[j].solved,stu[j].time);
  return 0;
}



