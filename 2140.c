#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
  char str[10005];
  while(scanf("%s", str)!=EOF){
    int i;
    for(i=0; i<strlen(str); i++){
      switch(str[i]){
      case 'b': str[i]=' ';break;
      case 'q': str[i]=',';break;
      case 't': str[i]='!';break;
      case 'm': str[i]='l';break;
      case 'i': str[i]='e';break;
      case 'c': str[i]='a';break;
      case 'a': str[i]='c';break;
      case 'e': str[i]='i';break;
      case 'l': str[i]='m';break;
      }

    }
    printf ("%s\n", str);
  }
  return 0;
}
