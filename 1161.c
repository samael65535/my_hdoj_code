#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
  char str[1005];
  while(gets(str)!=NULL){
    int i;
    for(i=0; i<strlen(str); i++){
      if(isupper(str[i])){
	str[i]=tolower(str[i]);
      }
    }
    printf ("%s\n", str);
  }
}
