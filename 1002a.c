#include<stdio.h>
#include<string.h>
int main()
{
 int i,n,la,lb,c[1024]={0},max,k,ci,j,A,B;
 char a[1024]={0},b[1024]={0};
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  scanf("%s%s",a,b);
  ci=0;
  max=la=strlen(a);
  lb=strlen(b);
  if(max<lb)max=lb;
  for(j=1;j<=max;j++)
  {
   if(la>=j)A=a[la-j]-'0';
   else A=0;
   if(lb>=j)B=b[lb-j]-'0';
   else B=0;
   k=A+B+ci;
   c[j]=k;
   ci=k/10;
  }
  if(ci)c[j]=ci;
  else j--;
  printf("Case %d:\n",i+1);
  printf("%s + %s = ",a,b);
  for(;j>0;j--)printf("%d",c[j]);
  if(i!=n-1)printf("\n\n");
  else printf("\n");
 }
 return 0;
}
