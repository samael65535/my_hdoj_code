#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* 注意是统计连续子串的长度不是字母的数目 */
int main(int argc, char *argv[])
{
  int n;
  char *str = (char *)malloc(sizeof(char)*10005);
  char t;
  int s = 0;
  int count[10001]={0}, i, k;
  while(scanf("%d", &n) != EOF){
    for(i = 0; i < n; i++){
      scanf("%s", str);
      t = str[0];
      s = 0;
      for(k = 0; k < strlen(str); k++){
	if(t == str[k]){
	  count[s]++;
	}else{
	  s = k;
	  t = str[s];
	  count[s] = 1;
	}
      }
      for(i = 0; i < strlen(str); i++){
	if(count[i] == 0){
	  continue;
	}else{
	  if(count[i] > 1)
	    printf ("%d", count[i]);
	  printf ("%c",str[i]);
	}
	count[i] = 0;
      }
    }
    printf ("\n");
  }
  return 0;
}
