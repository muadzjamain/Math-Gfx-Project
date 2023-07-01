#include <graphics.h>
using namespace std;

int main()
{
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    initwindow(1700, 800);

    // STICKMAN
    circle(150, 470, 40); //head
    line(150, 510, 150, 690); //body
    line(150, 530, 50, 580); //arm
    //line(150, 530, 250, 580); //arm
    line(150, 690, 80, 750); //leg
   // line(150, 690, 220, 750); //leg
    
    //seller
    circle(800, 470, 40); //head
    line(800, 510, 800, 570); //body

    line(800, 530, 700, 480);//arm
    rectangle(700, 430, 703, 480); //batang
    rectangle(700, 430, 775, 395); //flag
    outtextxy(716, 405, "RM5:00");

    line(800, 530, 900, 510); //arm
    rectangle(900, 460, 903, 510); //batang
    rectangle(900, 460, 970, 425); //flag
    outtextxy(910, 435, "RM5:00");


   //STALL
    rectangle(600, 770, 1200, 570); //wall
    rectangle(630, 570, 650, 350);
    rectangle(1155, 570, 1175, 350);
    rectangle(630, 330, 1175, 350);
 
    line(630, 330, 690, 280); //roof
    line(1116, 280, 1176, 330);
    line(690, 280, 1115, 280);

    settextstyle(BOLD_FONT, HORIZ_DIR, 5);
    outtextxy(630, 600, "RAHMAH");
    outtextxy(630, 650, "5TALL");

    //clouds
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

    //menu
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(925, 605, "SET A");
    outtextxy(1055, 605, "SET B");
    setcolor(WHITE);
    rectangle(900, 600, 1150, 740);
    line(1025, 600, 1025, 740);
    line(900, 625, 1150, 625);

    // (set A)
    setcolor(RED);
    rectangle(918, 675, 942, 705); //bekas
    setcolor(LIGHTRED);
    arc(930, 675, 360, 180, 12); //penutup
    setcolor(WHITE);
    rectangle(928, 650, 931, 663); //straw

    //burger (set A)
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

    //drink (set B)
    setcolor(RED);
    rectangle(1045, 675, 1069, 705); //bekas
    setcolor(LIGHTRED);
    arc(1057, 675, 360, 180, 12); //penutup
    setcolor(WHITE);
    rectangle(1055, 650, 1058, 663); //straw

    //donut(set B)
    setcolor(BROWN); //outer
    circle(1100, 680, 20);
    setcolor(WHITE); //inner
    circle(1100, 680, 8);
   
    setcolor(YELLOW);
    circle(1120, 695, 20);
    setcolor(WHITE);
    circle(1120, 695, 8);
    
    // Wait for user input before closing the graphics window
    getch();

    // Close graphics mode
    closegraph();
    return 0;
}
