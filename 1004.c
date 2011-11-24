#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001
int main(int argc, char *argv[])
{
  char *str[MAX];
  int n, x, i;
  int max=1;
  int count[MAX] = {0};
  while(scanf("%d", &n) != EOF && n!= 0){
    for(i = 1; i <= n; i++){
      str[i]=(char*)malloc(sizeof(char)*MAX); 
      scanf("%s", str[i]);
      for(x = 1; x < i; x++){
	if(strcmp(str[i], str[x]) == 0){
	  count[i]+=1;
	}
      }
    }
    for(x=1; x<i; x++){
      if(count[max]<count[x]) max=x;
    }
    printf ("%s\n", str[max]);
    max = 1;
  }
  return 0;
}

