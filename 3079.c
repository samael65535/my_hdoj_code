#include<stdio.h>
#include<ctype.h>
int main(int argc, char *argv[])
{
  int n, len;
  scanf("%d", &n);
  getchar();
  char *buf = (char *)malloc(sizeof(char)*50);
  while(n--){
    gets(buf);
    len = strlen(buf);
    while(len--){
      if(buf[len] == 'a' || buf[len] == 'e' || buf[len] == 'i' ||
	 buf[len] == 'o' || buf[len] == 'u' || buf[len] == 'A' ||
	 buf[len] == 'E' || buf[len] == 'I' || buf[len] == 'O' ||
	 buf[len] == 'U')
	buf[len] = toupper(buf[len]);
      else
	buf[len] = tolower(buf[len]);
	}
    printf ("%s\n", buf);
  }
  return 0;
}
