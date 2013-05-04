#include<stdio.h>
#include<math.h>
int main(int argc, char *argv[])
{
  int T, sum = 1,temp;
  int i=2;
  scanf("%d", &T);
  while(i<=T){
    if(T%i){ 
      i++;
    }else{
      sum += i;
      T = T/i;
      printf ("%d\n", i);
    }

  }
  printf ("%d\n", sum);
  return 0;
}
