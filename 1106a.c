#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
int cmp(const void *a,const void *b){  
    return *(int *)a-*(int *)b;  
}  
int main(){  
    char s[1001];  
    int len,i,sum,cnt;  
    while(scanf("%s",s)!=EOF){  
         getchar();  
         len=strlen(s);   
         cnt=0;  
         s[len]='5';  
         int a[1001]={0},b[1001],flag=0,start;  
         for(i=0;i<=len;i++){  
              if(s[i]!='5'){  
                   start=i;  
                   break;           
              }                 
         }  
         for(i=start;i<=len;i++){  
              if(s[i]!='5'){  
                  flag=0;  
                  a[cnt]=a[cnt]*10+(s[i]-'0');  
              }  
              else{  
                  if(flag==0){//不是连续5   
                      cnt++;  
                  }  
                  flag=1;   
              }             
         }  
         qsort(a,cnt,sizeof(a[0]),cmp);  
         for(i=0;i<cnt-1;i++){  
              printf("%d ",a[i]);                
         }  
         printf("%d\n",a[cnt-1]);                      
    }  
}  
