#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
  int n;
  char card[18];
  scanf("%d", &n);
  while(n--){
    scanf("%s", card);
    printf ("He/She is from ");
    switch(card[0]){
    case '3':
      if(card[1] == '3') printf ("Zhejiang");
      else printf ("Shanghai");
      break;
    case '1': 
      printf ("Beijing");
      break;
    case '7':
      printf ("Taiwan");
      break;
    case '8':
      if(card[1] == '1') printf ("Hong Kong");
      else printf ("Macao");
      break;
    case '5':
      printf ("Tibet");
      break;
    default:
      printf ("Liaoning");
    }
    printf (",and his/her birthday is on ");
    printf ("%c%c,%c%c,%c%c%c%c based on the table.\n",card[10], card[11],card[12], card[13], card[6], card[7], card[8], card[9]);
  }
  return 0;
}
