#include <stdio.h>
#include <string.h>
int main(){
  int n,i,num;
  char str[10001];
  scanf("%d",&n);
  while(n--){
    num=1;
    scanf("%s",str);
    for(i=0;i<strlen(str);i++){
      if(str[i]==str[i+1]){
	num++;
      }
      else{
	if(num<=1) {
	  printf("%c",str[i]);
	  num=1;}
	else{
	  printf("%d%c",num,str[i]);
	  num=1;}
      }
    }
    printf("\n");
  }
  return 0;
}
