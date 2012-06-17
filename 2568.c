#include<stdio.h>
int main()
{
  int n;
  scanf("%d", &n);
  while(n--){
    int i=0, b=0;
    scanf("%d", &i);
    while(i!=0){
      if(i%2==1){
	b++;
	i=(i-1)/2;
      }else{
	i/=2;
      }
    }
    printf("%d\n", b);
  }
  return 0;
}
