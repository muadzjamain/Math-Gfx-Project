#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <cmath>

void rotation(float a[][2], int n, int x_pivot,int y_pivot, int angle) 
{ 

    for(int i=0;i<n;i++)
    { 
        // Shifting the pivot point to the origin and the given points accordingly 
        int x_shifted = a[i][0] - x_pivot; 
        int y_shifted = a[i][1] - y_pivot; 
  
        // Calculating the rotated point co-ordinates  and shifting it back
        a[i][0] = x_pivot + (x_shifted*cos(angle)- y_shifted*sin(angle));  //cosA*x + -sinA *y         
        a[i][1] = y_pivot + (x_shifted*sin(angle)+ y_shifted*cos(angle));  //sinA*x + cosA*y
                           
	}	
    line(a[0][0], a[0][1],a[1][0], a[1][1]);
}

bool isMouseClicked(int mx, int my, int x[], int y[])
{

    return (x[0] <= mx) && (mx <= x[1]) && (y[0] <= my) && (my <= y[1]);
}

void findNewCoordinate(int s[][3], int p[][1])
{
    int temp[3][1] = {0};

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 1; j++)
            for (int k = 0; k < 3; k++)
                temp[i][j] += (s[i][k] * p[k][j]);

    p[0][0] = temp[0][0];
    p[1][0] = temp[1][0];
}

void scaling(int x[], int y[], int sx, int sy, int n)
{
    int s[3][3] = {sx, 0, 0, 0, sy, 0, 0, 0, 1};
    int p[3][1];

    for (int i = 0; i < n; i++)
    {
        p[0][0] = x[i];
        p[1][0] = y[i];

        findNewCoordinate(s, p);

        x[i] = p[0][0];
        y[i] = p[1][0];
    }
}

void translation(int x[], int y[], int dx, int dy, int n)
{
    int T[3][3] = {1, 0, dx, 0, 1, dy, 0, 0, 1};

    for (int i = 0; i < n; i++)
    {
        x[i] = x[i] + T[0][2]; // x+dx
        y[i] = y[i] + T[1][2]; // y+dy
    }
}
// shear in x-direction
void shearing(int c[], int d[], float shx, int n)
{
    float sh[3][3] = {1, shx, 0, 0, 1, 0, 0, 0, 1};

    for (int i = 0; i < n; i++)
    {
        c[i] = c[i] + (sh[0][1] * d[i]);
    }
}

void interpolation(float x1[], float y1[], float x2[], float y2[], int n)
{
    float x,y;
	float no_post=100;
	
	float m=no_post - 1; 
	float step=1/m;
	float t=0;
    while (t < 1)
    {
        for (int i = 0; i < n; i++)
        {

            x = (x1[i] * ((1 + cos(2 * t)) / 2)) + (x2[i] * ((1 - cos(2 * t)) / 2));
            y = (y1[i] * ((1 + cos(2 * t)) / 2)) + (y2[i] * ((1 - cos(2 * t)) / 2));

            t += step;
            putpixel(x, y, YELLOW);
        }
    }
}

void moving() // Moving Function (Translation)
{
    int h[] = {150};
    int g[] = {470};
    int s[] = {150, 150};
    int e[] = {510, 690};
    int p[] = {150, 50};
    int q[] = {530, 580};
    int u[] = {150, 80};
    int t[] = {690, 750};

    for (int i = 0; i <= 300; i++)
    {
        // STICKMAN
        setcolor(WHITE);
        translation(h, g, 1, 0, 1);
        circle(h[0], g[0], 40); // head
        translation(s, e, 1, 0, 2);
        line(s[0], e[0], s[0], e[1]); // body
        translation(p, q, 1, 0, 2);
        line(p[0], q[0], p[1], q[1]); // arm
        // line(150+i, 530, 250+i, 580); //arm
        translation(u, t, 1, 0, 2);
        line(u[0], t[0], u[1], t[1]); // leg
        // line(150+i, 690, 220+i, 750); //leg

        float arr0[][2]= {{150 + i, 530},{50 + i, 580}};
        setlinestyle(0, 0, 3);
        line(150+i, 530, 50+i, 580); //arm
        rotation (arr0, 2, 150 + i, 530, 180);

        float arr1[][2]= {{150 + i, 690},{80 + i, 750}};
        setlinestyle(0, 0, 3);
        line(150+i, 690, 80+i, 750); //leg
        rotation (arr1, 2, 150 + i, 690, 350);

        // seller
        circle(800, 470, 40);     // head
        line(800, 510, 800, 570); // body

        setcolor(WHITE);
        line(800, 530, 700, 480); // arm
        setcolor(RED);
        rectangle(700, 430, 703, 480); // batang
        setcolor(GREEN);
        rectangle(700, 430, 775, 395); // flag
        settextstyle(BOLD_FONT, HORIZ_DIR, 1);
        char word1[] = {'R', 'M', '5', '.', '0', '0', '\0'};
        outtextxy(705, 405, word1);

        setcolor(WHITE);
        line(800, 530, 900, 510); // arm
        setcolor(RED);
        rectangle(900, 460, 903, 510); // batang
        setcolor(GREEN);
        rectangle(900, 460, 970, 425); // flag
        settextstyle(BOLD_FONT, HORIZ_DIR, 1);
        outtextxy(903, 435, word1);

        // STALL
        setcolor(BROWN);
        rectangle(600, 770, 1200, 570); // wall
        rectangle(630, 570, 650, 350);
        rectangle(1155, 570, 1175, 350);
        rectangle(630, 330, 1175, 350);

        line(630, 330, 690, 280); // roof
        line(1116, 280, 1176, 330);
        line(690, 280, 1115, 280);

        setcolor(WHITE);
        settextstyle(BOLD_FONT, HORIZ_DIR, 5);
        char word2[] = {'R', 'A', 'H', 'M', 'A', 'H', '\0'};
        char word3[] = {'5', 'T', 'A', 'L', 'L', '\0'};
        outtextxy(630, 600, word2);
        outtextxy(630, 650, word3);

        // clouds
        setcolor(LIGHTBLUE);
        line(55, 100, 355, 100);
        arc(106, 100, 360, 180, 50);
        arc(206, 100, 360, 180, 80);
        arc(306, 100, 360, 180, 50);

        setcolor(LIGHTBLUE);
        line(400, 150, 700, 150);
        arc(450, 150, 360, 180, 50);
        arc(550, 150, 360, 180, 80);
        arc(650, 150, 360, 180, 50);

        setcolor(LIGHTBLUE);
        line(770, 100, 1070, 100);
        arc(820, 100, 360, 180, 50);
        arc(920, 100, 360, 180, 80);
        arc(1020, 100, 360, 180, 50);

        setcolor(LIGHTBLUE);
        line(1170, 150, 1470, 150);
        arc(1220, 150, 360, 180, 50);
        arc(1320, 150, 360, 180, 80);
        arc(1420, 150, 360, 180, 50);

        // menu
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
        char word6[] = {'R', 'M', '5', ' ', 'O', 'n', 'l', 'y', '!', '!', '\0'};
        outtextxy(925, 635, word6);
        outtextxy(1055, 635, word6);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        char word4[] = {'S', 'E', 'T', ' ', 'A', '\0'};
        char word5[] = {'S', 'E', 'T', ' ', 'B', '\0'};
        outtextxy(925, 605, word4);
        outtextxy(1055, 605, word5);
        setcolor(WHITE);
        rectangle(900, 600, 1150, 740);
        line(1025, 600, 1025, 740);
        line(900, 625, 1150, 625);

        // (set A)
        setcolor(RED);
        rectangle(918, 675, 942, 705); // bekas
        setcolor(LIGHTRED);
        arc(930, 675, 360, 180, 12); // penutup
        setcolor(WHITE);
        rectangle(928, 650, 931, 663); // straw

        // burger (set A)
        setcolor(BROWN);
        arc(980, 685, 360, 180, 15);
        setcolor(BROWN);
        rectangle(965, 685, 995, 689);
        setcolor(GREEN);
        rectangle(963, 690, 997, 694);
        setcolor(BROWN);
        rectangle(965, 695, 995, 699);
        setcolor(BROWN);
        rectangle(965, 700, 995, 706);

        // drink (set B)
        setcolor(RED);
        rectangle(1045, 675, 1069, 705); // bekas
        setcolor(LIGHTRED);
        arc(1057, 675, 360, 180, 12); // penutup
        setcolor(WHITE);
        rectangle(1055, 650, 1058, 663); // straw

        // donut(set B)
        setcolor(BROWN); // outer
        circle(1100, 680, 20);
        setcolor(WHITE); // inner
        circle(1100, 680, 8);

        setcolor(YELLOW);
        circle(1120, 695, 20);
        setcolor(WHITE);
        circle(1120, 695, 8);

        delay(10);
        cleardevice();
    }
}

int main()
{
    initwindow(getmaxwidth(), getmaxheight(), "Menu Rahmah");

    int gm, i, a;
    initwindow(1700, 800);

    // Set initial position of stickman

    moving();

    ////*  Static Stickman, stall, Cloud & etc DOWN HERE  *//////

    char ch = 0;

    while (ch != 27) // 27 is ESC key
    {

        // STICKMAN
        circle(150 + 300, 470, 40);           // head
        line(150 + 300, 510, 150 + 300, 690); // body
        line(150 + 300, 530, 50 + 300, 580);  // arm
        // line(150+300, 530, 250+300, 580); //arm
        line(150 + 300, 690, 80 + 300, 750); // leg
        // line(150+300, 690, 220+300, 750); //leg

        float arr0[][2]= {{150 + 300, 530},{50 + 300, 580}};
        setlinestyle(0, 0, 3);
        line(150 + 300, 530, 50 + 300, 580); //arm
        rotation (arr0, 2, 150 + 300, 530, 180);
        //line(150+300, 530, 250+300, 580); //arm

        float arr1[][2]= {{150 + 300, 690},{80 + 300, 750}};
        setlinestyle(0, 0, 3);
        line(150+300, 690, 80+300, 750); //leg
        rotation (arr1, 2, 150 + 300, 690, 350);
        //line(150+300, 690, 220+300, 750); //leg
       
        

        // seller
        circle(800, 470, 40);     // head
        line(800, 510, 800, 570); // body

        setcolor(WHITE);
        line(800, 530, 700, 480); // arm
        setcolor(RED);
        rectangle(700, 430, 703, 480); // batang
        setcolor(GREEN);
        rectangle(700, 430, 775, 395); // flag
        settextstyle(BOLD_FONT, HORIZ_DIR, 1);
        char word1[] = {'R', 'M', '5', '.', '0', '0', '\0'};
        outtextxy(705, 405, word1);

        setcolor(WHITE);
        line(800, 530, 900, 510); // arm
        setcolor(RED);
        rectangle(900, 460, 903, 510); // batang
        setcolor(GREEN);
        rectangle(900, 460, 970, 425); // flag
        settextstyle(BOLD_FONT, HORIZ_DIR, 1);
        outtextxy(903, 435, word1);

        // STALL
        setcolor(YELLOW);
        rectangle(600, 770, 1200, 570); // wall
        rectangle(630, 570, 650, 350);
        rectangle(1155, 570, 1175, 350);
        rectangle(630, 330, 1175, 350);

        setcolor(YELLOW);
        line(630, 330, 690, 280); // roof
        line(1116, 280, 1176, 330);
        line(690, 280, 1115, 280);

        setcolor(YELLOW);
        settextstyle(BOLD_FONT, HORIZ_DIR, 4);
        char word7[] = {'C', 'l', 'i', 'c', 'k', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 'm', 'e', 'n', 'u', ' ', 't', 'o', ' ', 'c', 'h', 'e', 'c', 'k', ' ', 'o', 'u', 't', ' ', 'w', 'h', 'a', 't', ' ', 'w', 'e', ' ', 'o', 'f', 'f', 'e', 'r', '!', '\0'};
        outtextxy(450, 190, word7);

        setcolor(WHITE);
        settextstyle(BOLD_FONT, HORIZ_DIR, 5);
        char word2[] = {'R', 'A', 'H', 'M', 'A', 'H', '\0'};
        char word3[] = {'5', 'T', 'A', 'L', 'L', '\0'};
        outtextxy(630, 600, word2);
        outtextxy(630, 650, word3);

        // clouds
        setcolor(LIGHTBLUE);
        line(55, 100, 355, 100);
        arc(106, 100, 360, 180, 50);
        arc(206, 100, 360, 180, 80);
        arc(306, 100, 360, 180, 50);

        setcolor(LIGHTBLUE);
        line(400, 150, 700, 150);
        arc(450, 150, 360, 180, 50);
        arc(550, 150, 360, 180, 80);
        arc(650, 150, 360, 180, 50);

        setcolor(LIGHTBLUE);
        line(770, 100, 1070, 100);
        arc(820, 100, 360, 180, 50);
        arc(920, 100, 360, 180, 80);
        arc(1020, 100, 360, 180, 50);

        setcolor(LIGHTBLUE);
        line(1170, 150, 1470, 150);
        arc(1220, 150, 360, 180, 50);
        arc(1320, 150, 360, 180, 80);
        arc(1420, 150, 360, 180, 50);

        // menu
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
        char word6[] = {'R', 'M', '5', ' ', 'O', 'n', 'l', 'y', '!', '!', '\0'};
        outtextxy(925, 635, word6);
        outtextxy(1055, 635, word6);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        char word4[] = {'S', 'E', 'T', ' ', 'A', '\0'};
        char word5[] = {'S', 'E', 'T', ' ', 'B', '\0'};
        outtextxy(925, 605, word4);
        outtextxy(1055, 605, word5);
        setcolor(WHITE);
        // rectangle(900, 600, 1150, 740);
        line(1025, 600, 1025, 740);
        line(900, 625, 1150, 625);

        int x[] = {900, 1150};
        int y[] = {600, 740};
        rectangle(x[0], y[0], x[1], y[1]);

        // (set A)
        setcolor(RED);
        rectangle(918, 675, 942, 705); // bekas
        setcolor(LIGHTRED);
        arc(930, 675, 360, 180, 12); // penutup
        setcolor(WHITE);
        rectangle(928, 650, 931, 663); // straw

        // burger (set A)
        setcolor(BROWN);
        arc(980, 685, 360, 180, 15);
        setcolor(BROWN);
        rectangle(965, 685, 995, 689);
        setcolor(GREEN);
        rectangle(963, 690, 997, 694);
        setcolor(BROWN);
        rectangle(965, 695, 995, 699);
        setcolor(BROWN);
        rectangle(965, 700, 995, 706);

        // drink (set B)
        setcolor(RED);
        rectangle(1045, 675, 1069, 705); // bekas
        setcolor(LIGHTRED);
        arc(1057, 675, 360, 180, 12); // penutup
        setcolor(WHITE);
        rectangle(1055, 650, 1058, 663); // straw

        // donut(set B)
        setcolor(BROWN); // outer
        circle(1100, 680, 20);
        setcolor(WHITE); // inner
        circle(1100, 680, 8);

        setcolor(YELLOW);
        circle(1120, 695, 20);
        setcolor(WHITE);
        circle(1120, 695, 8);

        int mx, my;
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, mx, my);

            cleardevice();

            if (isMouseClicked(mx, my, x, y))
            {

                scaling(x, y, 3, 3, 2);
                rectangle(x[0], y[0], x[1], y[1]);

                translation(x, y, -2300, -1600, 2);
                // Enlarged menu
                setcolor(WHITE);
                settextstyle(DEFAULT_FONT, HORIZ_DIR, 6);
                outtextxy(460, 215, word4);
                outtextxy(855, 215, word5);
                settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
                char word6[] = {'R', 'M', '5', ' ', 'O', 'n', 'l', 'y', '!', '!', '\0'};
                outtextxy(480, 300, word6);
                outtextxy(860, 300, word6);
                setcolor(WHITE);
                rectangle(x[0], y[0], x[1], y[1]);
                line(775, 200, 775, 620);
                line(400, 280, 1150, 280);

                // (set A)
                setcolor(RED);
                rectangle(454, 425, 526, 535); // bekas
                setcolor(LIGHTRED);
                arc(490, 425, 360, 180, 36); // penutup
                setcolor(WHITE);
                int c[] = {484, 493};
                int d[] = {350, 389};
                shearing(c, d, 0.05, 2);
                int arr1[] = {c[0], d[0], c[0] + 9, d[0], 493, d[1], 484, d[1], c[0], d[0]};
                drawpoly(5, arr1); // straw

                // burger (set A)
                setcolor(BROWN);
                arc(640, 455, 360, 180, 48);
                setcolor(BROWN);
                rectangle(595, 455, 685, 467);
                setcolor(GREEN);
                rectangle(589, 470, 691, 482);
                setcolor(BROWN);
                rectangle(595, 485, 685, 497);
                setcolor(BROWN);
                rectangle(595, 500, 685, 518);

                // drink (set B)
                setcolor(RED);
                rectangle(835, 425, 907, 515); // bekas
                setcolor(LIGHTRED);
                arc(871, 425, 360, 180, 36); // penutup
                setcolor(WHITE);
                int r[] = {865, 874};
                int z[] = {350, 389};
                shearing(r, z, 0.05, 2);
                int arr2[] = {r[0], z[0], r[0] + 9, z[0], 874, z[1], 865, z[1], r[0], z[0]};
                drawpoly(5, arr2); // straw

                // donut(set B)
                setcolor(BROWN); // outer
                circle(1000, 440, 60);
                setcolor(WHITE); // inner
                circle(1000, 440, 24);

                setcolor(YELLOW);
                circle(1060, 485, 60);
                setcolor(WHITE);
                circle(1060, 485, 24);

                 // form dotline using interpolation & putpixel()
                float X1[] = {450, 350, 350, 350, 1190, 1180, 1160,1100};
                float Y1[] = {170, 230, 570, 660, 670, 580, 260,160};
                float X2[] = {350, 100, 220, 190, 1300, 1490, 1350,1380};
                float Y2[] = {80, 280, 430, 730, 790, 450, 390,10};

                interpolation(X1, Y1, X2, Y2, 8);
                break;
            }
        }
    }

    // Wait for user input before closing the graphics window 
    getch();
}