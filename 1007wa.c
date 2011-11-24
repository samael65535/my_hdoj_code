#include<stdio.h>
#include<math.h>
/* 解题思路,如果当前点比当前半径小就更新点   思路错误,可能新的两点与之前没有联系*/
int main(int argc, char *argv[])
{
  int n;
  float x1,y1,x2,y2;
  float x, y;
  float r, rt, r1, r2;
  float rx, ry;
  int i;
  while(scanf("%d", &n) !=EOF && n>=2){
    scanf("%f%f", &x1, &y1);
    scanf("%f%f", &x2, &y2);
    r = pow(fabs(x1-x2), 2)+pow(fabs(y1-y2), 2);
    for(i=2; i<n; i++){
      rx = (x1+x2)/2;
      ry = (y1+y2)/2;
      scanf("%f%f", &x, &y);
      rt = pow(fabs(x-rx), 2)+pow(fabs(y-ry), 2);
      if(rt < r){
	r1 = pow(fabs(rx-x1), 2)+pow(fabs(y2-ry), 2);
	r2 = pow(fabs(rx-x2), 2)+pow(fabs(y2-ry), 2);
	if(r2>r1){
	  r = r2;
	  x2 = x;
	  y2 = y;
	}else{
	  r = r1;
	  x1 = x;
	  y1 = y;
	}
      }
    }
    printf ("%.2f\n", sqrt(r)/2);
  }
  return 0;
}
