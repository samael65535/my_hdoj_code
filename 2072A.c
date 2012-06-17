#include <stdio.h>
#include <string.h>
#include <math.h>
char word[1000];
char arr[100][100];  //arr用于存储以前出现过的单词
int main()
{
  int len, pos;
  char temp[100];
  while(gets(word) && strcmp(word, "#") != 0)//题目要求不是文章结尾为，注意strcmp用比较用“#”
    {
      len = strlen(word);//总长度（包括空格）
      pos = 0;
      int cnt = 0;
      // pos加单词长度一直到>len
      while(pos <= len)
	{
	  sscanf(word + pos, "%s", temp); //把一个单词存入temp,空格省去(sscanf应该是读到空格截止，对于sscanf,空格很重要)
	  //word + pos为指针指向位置
	  //printf("%s++++++++++++++++++++\n",temp);
	  int k;
	  for(k = 0; k < cnt; ++k)
	    if(strcmp(temp, arr[k]) == 0)   //如果和以前存入的单词相同，则不计数
	      break;
	  if(k == cnt)
	    strcpy(arr[cnt++], temp);   //把temp存入arr,并计数器cnt加一
	  pos += strlen(temp) + 1;// +1表示加上空格，最后一次pos肯定会大于len
	}
      printf("%d\n", cnt);
    }
  return 0;
}
