#include<stdio.h>
#include<string.h>
char a[5000], b[5000], c[5000];
char fun(char *x)
{
  int flag, i;
  /* for(i=strlen(x)-1; i>=0; i--){ */
  /*   if(x[i]=='0' && flag==0){  */
  /*     x[i]='\0'; */
  /*   }else{ */
  /*     flag=1; */
  /*   } */
  /* } */
  for(i=0; i<strlen(x)&&x[i]==0; i++);
  return x=x+i;
}
int main(int argc, char *argv[])
{
  while(scanf("%s%s", &a, &b)!=EOF){
    int i, flag=1, j=0;
    a=fun(a);
    printf ("%s\n", a);
    /* for(i=strlen(a)-1; i>=0; i--) */
    /*   if(a[i]=='0' && flag==0) c[j++]=a[i]; */
    /* /\* printf("%s\n",a==b?"YES":"NO"); *\/ */
  }
  return 0;
}
