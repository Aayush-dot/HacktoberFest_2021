#include<stdio.h>

#include<conio.h>

#include<graphics.h>







const int INF = 32768;
void drawLine(int X0, int Y0, int Xend, int Yend) {
 int gd = 1, gm;
 initgraph(&gd, &gm, "");

 int dy = Yend - Y0, dx = Xend - X0, m = 0;
 if(dx == 0) m = INF;
 else if(abs(dy) > abs(dx)) m = 2;
 else if(abs(dy) < abs(dx)) m = 0;
 else m = 1;
 dx = abs(dx);
 dy = abs(dy);
 if( m < 1) {
 int X = X0, Y = Y0, d0 = dy - dx/2;
 int d = d0;
 while(X < Xend) {
 putpixel(X , Y, CYAN);
 X++;
 if(d < 0) d = d + dy;
 else {
 d = d + (dy - dx);
 if(Y > Yend) Y--;
 else Y++;
 }
 }
 while(X > Xend) {
 putpixel(X, Y, CYAN);
 X--;
 if(d < 0) d = d + dy;
 else {
 d = d + (dy - dx);
 if(Y > Yend) Y--;
 else Y++;
 }
 }
 }
 else {
 int X = X0, Y = Y0, d0 = dx - dy/2;
 int d = d0;
 while(Y < Yend) {
 putpixel(X, Y, CYAN);
 Y++;
 if(d < 0) d = d + dx;
 else {
 d = d + (dx - dy);
 if(X > Xend) X--;
 else X++;
 }
 }
 while(Y > Yend) {
 putpixel(X, Y, CYAN);
 Y--;
 if(d < 0) d = d + dx;
 else {
 d = d + (dx - dy);
 if(X > Xend) X--;
 else X++;
 }
 }
 }

 getch();
 closegraph();
}
int main() {
 int X0, Y0, Xend, Yend;
 printf("Enter X0\n");
 scanf("%d", &X0);
 printf("Enter Y0\n");
 scanf("%d", &Y0);
 printf("Enter X1\n");
 scanf("%d", &Xend);
 printf("Enter Y1\n");
 scanf("%d", &Yend);

 printf("\n\n\n\n");
 printf("######################");
 printf("\n");
 printf("Line: (%d, %d) to (%d, %d)", X0, Y0, Xend, Yend);
 printf("\n");
 printf("######################");
 drawLine(X0, Y0, Xend, Yend);
}
