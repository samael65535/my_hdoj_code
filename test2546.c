#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
  int i;
  for(i=0; i<500; i++){
    int n=rand()%1000+1;
    int j;
    printf ("%d\n", n);
    for(j=0; j<n; j++)
      printf ("%d ",rand()%50+1);
    printf ("\n");
    printf ("%d\n", rand()%10+1);
  }
  printf ("0\n");
  return 0;
}
