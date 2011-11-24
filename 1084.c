#include<stdio.h>
/* 分数:  用N*3数组实现? */
int main(int argc, char *argv[])
{
  int students[101][3];
  int n, i, h, m ,s, k, p, t, min;
  while(scanf("%d", &n) != EOF && n > -1){
    int c[6] = {0};
    p = 1;
    t = 0;
    for(i=0; i<n; i++){
      scanf("%d%d:%d:%d", &students[i][0], &h, &m, &s);
      students[i][1] = h*10000+m*100+s;
      c[ students[i][0] ]++;
     
    }
    for(k=1; k<5; k++){
      p = 1;
      for(i=0; i<n; i++){
	min = 1000000;
	for(s=0; s<n; s++){
	  if(students[s][0] == k && students[s][1]<=min && students[s][2] == 0){
	    min = students[s][1];
	    t = s;
	  }
	}
	c[k] = c[k]%2 ? c[k]-1 : c[k]; 
	if(p <= c[k]/2) students[t][2] = p++;
	else break;
      }
    }
    for(i=0; i<n; i++){
      switch(students[i][0]){
      case 0:
	printf ("50\n");
	break;
      case 1:
	if(students[i][2]!=0) printf ("65\n");
	else printf ("60\n");
	break;
      case 2:
	if(students[i][2]!=0) printf ("75\n");
	else printf ("70\n");
	break;
      case 3:
	if(students[i][2]!=0) printf ("85\n");
	else printf ("80\n");
	break;
      case 4:	
	if(students[i][2]!=0) printf ("95\n");
	else printf ("90\n");
	break;
      case 5:
	printf ("100\n");
	break;
      }
      students[i][0] = students[i][1] = students[i][2]= 0;
    }
    printf ("\n");
  }
  printf ("\n");
  return 0;
}
