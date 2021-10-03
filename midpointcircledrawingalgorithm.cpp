#include<stdio.h>

#include<conio.h>

#include<graphics.h>


const int INF = 32768;
const int OX = 100, OY = 100;

plotInAllOctants(int x, int y, int h, int k) {
   // 1st Quadrant
    int c=rand()%8;
putpixel(x + OX + h, y + OY + k,YELLOW);
   putpixel(y + OX + h, x + OY + k, YELLOW);

   // 2nd Quadrant
   putpixel(-x + OX + h, y + OY + k, YELLOW);
   putpixel(-y + OX + h, x + OY + k, YELLOW);

   // 3rd Quadrant
   putpixel(-x + OX + h, -y + OY + k,YELLOW);
   putpixel(-y + OX + h, -x + OY + k, YELLOW);

   // 4th Quadrant
   putpixel(x + OX + h, -y + OY + k,YELLOW);
   putpixel(y + OX + h, -x + OY + k, YELLOW);
}

void drawCircle(int h, int k, int r) {

  int gd = 1, gm;
  initgraph(&gd, &gm, "");


  int x = 0, y = r, d = 1-r;

  while(x <=y) {
    plotInAllOctants(x, y, h, k);
    if(d < 0) d = d + 2*x + 3;
    else {
        d = d + 2*(x - y) + 5;
        y--;
    }
    x++;
  }
  //-------------------------

 getch();
closegraph();
}

int main() {
    int h, k, r;

       printf(" Enter the center of circle(h, k) and radius(r) : \n");
    scanf("%d", &h);
    scanf("%d", &k);
    scanf("%d", &r);

    printf("Circle: (x-%d)^2 + (y-%d)^2 = %d^2", h, k, r);

    drawCircle(h, k, r);
}
