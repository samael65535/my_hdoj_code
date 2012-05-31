/* 有问题,可以用标准库函数做,自己写为什么出错
   错误用例是什么?*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[100000], b[100000];
char* fun(char x[]) 
{
  int i, j=0, flag=0, XC=-1,flagP=0;
  char *y=(char *)malloc(sizeof(char)*100000);
  for(i=0; x[i]!='\0'; i++){
    if(x[i]=='0' && flag==0)
      continue;
    if(x[i]=='.') flagP=1;
    y[j++]=x[i];
    flag=1;
  }
  for(i=strlen(y)-1; flagP&&y[i]=='0'; i--) y[i]=0;
  if(y[strlen(y)-1]=='.') y[strlen(y)-1]=0;
  return y;
}
int main(int argc, char *argv[])
{
  while(scanf("%s%s", a, b)!=EOF){
    char *x=fun(a);
    char *y=fun(b);
    if(!strcmp(x, y))printf ("YES\n");
    else printf ("NO\n");
  }
  return 0;
}

