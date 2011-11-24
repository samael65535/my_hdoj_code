#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
  int n, j=0;
  char *str= (char *)malloc(sizeof(char) * 100);
  char t;
  scanf("%d", &n);
  getchar();
  while(n--){
    while(1){
      t = getc(stdin);
      if(t == ' ' || t == '\n'){
	for(j; j>=0; j--){
	  printf ("%c",str[j]);
	  str[j] = '\0';
	}
	if(t == ' '){ 
	  j = 0;
	  printf (" ");
	} else {
	  j = 0;
	  break;
	}
      }else{
	str[j++] = t;
      }
    }
    printf ("\n");
  }
  return 0;
}
