#include<stdio.h>
int x[14];
int test(int k,int m)  
{  
  int i,j=0,len=k*2;  
  for(i=0;i<k;i++){  
    j=(j+m-1)%(len-i);    /* 约瑟夫环公式   */
    if(j<k)  
      return 0;     /* 遇到前k轮中有小于k的直接返回0    */
  }  
  return 1;  
}  
int main(int argc, char *argv[])
{
  int k,m;
  for(k=1; k<15; k++){
    m=k+1;
    while(1){
      if(test(k,m))     /* m%(k+1)==0的情况   */
	{  
	  x[k]=m;  
	  break;  
	}  
      if(test(k,m+1))     /* m%(k+1)==1的情况   */
	{  
	  x[k]=m+1;  
	  break;  
	}  
      m+=k+1;  
    }
  }
  while(scanf("%d", &k) != EOF && k){
    printf ("%d\n", x[k]);
  }
  return 0;
}
