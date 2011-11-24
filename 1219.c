#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
  int count[26]={0};
  int i = 0, len;
  char *buf = (char*)malloc(sizeof(char)*100002);
  while(gets(buf)){
    len = strlen(buf);		/* 注意优化 */
    for(i=0; i<len; i++){
      if(buf[i]>='a' && buf[i]<='z'){
	count[buf[i]-97]++;
      }
    }
    for(i=0; i<26; i++){
      printf ("%c:%d\n",i+97, count[i]);
      count[i] = 0;
    }
    printf ("\n");
  }
  free(buf);
  return 0;
}
