 #include<stdio.h>
 #include <memory.h>
 #include <math.h>
int num;
int result[21];
int visited[21];
int prim[40]={0};
int caseFlag;
int caseCnt=0;
void Prim()
{
  int i, n;
  for(n=1;n<40;n++) 
    { 
      int k=sqrt((double)n); 
      for(i=2;i<=k;i++) 
	if(n%i==0) 
	  break; 
      if(i==k+1)
	{ 
	  prim[n]=1;
	} 
    } 
}
void dfs(int prev)
{
  int i;
  for (i=2;i<=num;i++)
    {
      if(visited[i]||!prim[i+result[prev]]) continue;
      visited[i]=1;
      result[prev+1]=i;
      dfs(prev+1);
      visited[i]=0;
    }
  if(prev==num&&prim[1+result[num]])
    {
      if(caseFlag)
	{
	  printf("Case %d:\n",caseCnt);
	  caseFlag=0;
	}
      for (i=1;i<num;i++)
	printf("%d ",result[i]);
      printf("%d",result[num]);
      printf("\n");
    }
}
 int main()
 {
     //freopen("Prime Ring Problem.txt","r",stdin);
     Prim();
     while (scanf("%d",&num)!=EOF)
     {
         caseCnt++;
         caseFlag=1;
         memset(visited,0,sizeof(visited));
         result[1]=1;
         dfs(1);
         printf("\n");
     }
     return 0;
 }
