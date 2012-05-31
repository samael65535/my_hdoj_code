#include<stdio.h>
#define MAX 6000
int main(int argc, char *argv[])
{
  int n=2, i;
  int num[MAX];
  long long t2, t3, t5, t7;
  long long i2, i3, i5, i7, temp;
  num[1]=1;
  i2=i3=i5=i7=1;
  for(i=2; i<MAX; i++){
    temp=t2=num[i2]*2;
    t3=num[i3]*3;
    t5=num[i5]*5;
    t7=num[i7]*7;
    if(temp>t3){temp=t3;}
    if(temp>t5){temp=t5;}
    if(temp>t7){temp=t7;}
    if(temp==t2) i2++;
    if(temp==t3) i3++;
    if(temp==t5) i5++;
    if(temp==t7) i7++;
    num[i]=temp;
    /* printf ("%lld\t",num[i]); */
  }
  char* s[4]={"th", "st", "nd", "rd"};
  while(scanf("%d", &n)!=EOF && n){
    if((n%100)/10==1)
      printf ("The %d%s humble number is %d.\n",n, s[0], num[n]);
    else{
      if(n%10<4 && n%10)
	printf ("The %d%s humble number is %d.\n", n, s[n%10], num[n]);
      else 
	printf ("The %d%s humble number is %d.\n", n, s[0], num[n]);
    }
  }
  return 0;
}
