/* 统计不同的单词量 */
#include<string.h>
#include<stdio.h>
char str[10000];
char count[100][100];

int cmp(const void *a, const void *b)
{
  return strcmp( ((const char*)a), ((const char*)b) );
}

int main(int argc, char *argv[])
{
  int len, pos;
  char temp[100];
  while(gets(str) && strcmp(str, "#")!=0){
    int i, j, k, sum=0;
    len = strlen(str);
    pos = 0;
    int cnt = 0;
    while(pos <= len){
      sscanf(str + pos, "%s", temp); 
      pos += strlen(temp) + 1;
      strcpy(count[cnt++], temp);
    }
    qsort(count, cnt, sizeof(count[0]),cmp);
    sum=1;
    for(i=1; i<cnt; i++){
      if(strcmp(count[i], count[i-1])) sum++;
    }
    printf ("%d\n", sum);
  }
  return 0;
}
