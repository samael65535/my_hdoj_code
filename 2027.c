#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
  int n, flag=0;
  scanf("%d", &n);
  getchar();
  while(n--){
    char a[105];
    gets(a);
    int sum[6]={0};
    int i;
    for(i=0; i<strlen(a); i++){
      switch(a[i]){
      case 'a': sum[1]++; break;
      case 'e': sum[2]++; break;
      case 'i': sum[3]++; break;
      case 'o': sum[4]++; break;
      case 'u': sum[5]++; break;
      }
    }
    printf("a:%d\n",sum[1]);
    printf("e:%d\n",sum[2]);
    printf("i:%d\n",sum[3]);
    printf("o:%d\n",sum[4]);
    printf("u:%d\n",sum[5]);
    if(n!=0) printf ("\n");
  }
  return 0;
}
