/* GROUP 3 (MATH FOR COMPUTER GRAPHICS) hello
- RAZIQ FITRI BIN ZAIFULNIZAM (A22EC0265)
- MUHAMMAD MUADZ BIN JAMAIN (B22EC0032)
- NUR ALIA MAISARAH BINTI WAN ASMIRA (A22EC0242)
- YAP YEE JIA (A22EC0119)
*/

////////////////////////////////////////////////////////////////

#include<stdio.h> 
#include<math.h> 
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include<dos.h>
using namespace std;

#define SIN(x) sin(x * 3.141592653589/180) 
#define COS(x) cos(x * 3.141592653589/180)   
 
void rotation(float a[][2], int n, int x_pivot,int y_pivot, int angle) 
{ 
	/*
	homogenous matrices for rotation (formula slide pg 16):
	
	x' = cosA*x + -sinA *y
	y' = sinA*x + cosA*y
	1  = 1
	
	*/
	
    for(int i=0;i<n;i++)
    { 
        // Shifting the pivot point to the origin and the given points accordingly 
        int x_shifted = a[i][0] - x_pivot; 
        int y_shifted = a[i][1] - y_pivot; 
  
        // Calculating the rotated point co-ordinates  and shifting it back
        a[i][0] = x_pivot + (x_shifted*COS(angle)- y_shifted*SIN(angle));  //cosA*x + -sinA *y         
        a[i][1] = y_pivot + (x_shifted*SIN(angle)+ y_shifted*COS(angle));  //sinA*x + cosA*y
                           
	}	
    line(a[0][0], a[0][1],a[1][0], a[1][1]);
} 

void translation(float b[][2],int n,int T[]) 
{ 
	/*
	homogenous matrices for rotation (formula slide pg 16):
	
	x' = x+0+dx = x+dx
	y' = 0+y+dy = y+dy
	1  = 1
	
	*/
  	
    // calculating translated coordinates 
	for(int i=0;i<n;i++)
    {
    b[i][0] = b[i][0] + T[0]; //x+dx
    b[i][1] = b[i][1] + T[1]; //y+dy
  	}

    // drawing translated line using graphics functions 
    if(n>2){    	
    setcolor(CYAN); 
	line(b[0][0], b[0][1], b[1][0], b[1][1]);
	line(b[2][0], b[2][1], b[3][0], b[3][1]);
	line(b[4][0], b[4][1], b[5][0], b[5][1]);
	line(b[6][0], b[6][1], b[7][0], b[7][1]);
	line(b[8][0], b[8][1], b[9][0], b[9][1]);
	line(b[10][0], b[10][1], b[11][0], b[11][1]);
	}  
	
    else{
    setcolor(CYAN); 
	line(b[0][0], b[0][1], b[1][0], b[1][1]);
	}    
} 

void findNewCoordinate(int s[][2], int p[][1]) 
{ 
    int temp[2][1] = { 0 }; 
  
    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 1; j++) 
            for (int k = 0; k < 2; k++) 
                temp[i][j] += (s[i][k] * p[k][j]); 
  
    p[0][0] = temp[0][0]; 
    p[1][0] = temp[1][0]; 
} 
  
void scale(int x[], int y[], int sx, int sy, int n ) 
{ 
    // Initializing the Scaling Matrix. 
    int s[2][2] = { sx, 0, 0, sy }; 
    int p[2][1]; 
  
    // Scaling the triangle 
    for (int i = 0; i < n; i++) 
    { 
        p[0][0] = x[i]; 
        p[1][0] = y[i]; 
  
        findNewCoordinate(s, p); 
  
        x[i] = p[0][0]; 
        y[i] = p[1][0];         
    } 
} 

void interpolation(float x1[], float y1[], float x2[], float y2[], int n)
{
	/*  interpolate between (x1,y1) and (x2,y2)
	using Matrix notation -> n= n1 cos^2(t) + n2 sin^2 (t)
	cos^2 = 1+cos(2*t) /2
	sin^2 = 1-cos(2*t) /2
	
	*/
	
	float x,y;
	float no_post=100;
	
	float m=no_post - 1; 
	float step=1/m;
	float t=0;
	do{
		
	for(int i=0;i<n;i++){
		
		x=(x1[i]*((1+cos(2*t))/2)) + (x2[i]*((1-cos(2*t))/2)); 
		y=(y1[i]*((1+cos(2*t))/2)) + (y2[i]*((1-cos(2*t))/2));
		
		t+=step;
		putpixel(x,y,WHITE); }
		
	}while(t<1);
}

printMsg()
{	char text1[][1] ={' ','S','T','A','Y',' ','A','T',' ','H','O','M','E',' ','A','N','D',' ','S','T','A','Y',' ','S','A','F','E','!',' '};

	int j=0;
	for(int i=0;i<30;i++){
			delay(350); //adjust speed to display text
			setcolor(i);
			settextstyle(8, 0, 40);
			outtextxy(50+j,600,&text1[i][0]);
			continue;
	}
}

main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
  	
  	int set=0;
  	do{
  		
	//house 
	float arr0[][2]= {{150,150},{0,200}}; //coordinates of left roof
	setcolor(CYAN);
	setlinestyle(0, 0, 3);
	line(150,150,0,200);
	rotation(arr0,2,150,150,217); //form right roof by rotating the line of left roof at point (150,150) at angle 217
	
	float arr1[][2]= {{30,190},{30,300}}; // vertical (left) line of house 
	int arr2[] = {50,135,50,175,85,163,85,135,50,135}; //coordinates of chimney          
	
	int trans1[]={240,0}; //move right 240
	int trans2[]={0,100}; //move up 100
	line(arr1[0][0],arr1[0][1],arr1[1][0],arr1[1][1]);
	
	translation(arr1,2,trans1);  // translate 3 times of left line
	translation(arr1,2,trans2);  //  to
	translation(arr1,2,trans2);  //form a longer (right) vertical line of house
	drawpoly(5,arr2); 			//form chimney
	
//************************************************	

	// line link with heart
	line(1170,500,840,500); //horizontal line
	line(700,500,540,500);  
	line(270,500,400,500);  
	
	float _line1[][4]={{400,500,430,380},{430,380,460,600},{460,600,490,450},{490,450,510,550,},{510,550,530,480},{530,480,540,500}}; 
	float _line2[][2]={{400,500},{430,380},{430,380},{460,600},{460,600},{490,450},{490,450},{510,550},{510,550},{530,480},{530,480},{540,500}};
	
	for(int i=0;i<11;i++){
		line(_line1[i][0],_line1[i][1],_line1[i][2],_line1[i][3]);
	}
	
	int trans3[]={300,0};
	translation(_line2,12,trans3);
	
//************************************************
	//form the shape of heart using 2 circles and 1 polygon
	//red heart
	setcolor(LIGHTRED);
	circle(120,220,40);
	setfillstyle(SOLID_FILL,LIGHTRED);
	floodfill(120,220,LIGHTRED);
	circle(180,220,40);
	floodfill(180,220,LIGHTRED);
	int arr3[] = {83,238,216,238,150,300,83,238};                
	fillpoly(4, arr3);
	
//************************************************	

	//form a bigger blue heart using scaling
	setcolor(LIGHTBLUE);
	int _x1[] ={120};
	int _y1[] ={220};
	scale(_x1,_y1,9,1,1); //scale 1st circle
	circle(_x1[0],_y1[0],42*3);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	floodfill(_x1[0],_y1[0],LIGHTBLUE);
	
	int _x2[] ={180};
	int _y2[] ={220};
	scale(_x2,_y2,7,1,1); // scale 2nd circle
	circle(_x2[0],_y2[0],42*3);
	floodfill(_x2[0],_y2[0],LIGHTBLUE);
	
	int arr[] = {985,300,1355,300,1170,500,985,300};                
	fillpoly(4, arr);  
	
//************************************************
	//virus	
	delay(500);
	setcolor(WHITE);
	circle(400,100,42);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(400,100,WHITE);	
	circle(540,245,42);
	floodfill(540,245,WHITE);
		
	int arr4[][2]={{330,100},{400,30},{470,100},{400,170}};	 //1st virus surrounding big circle
	int arr5[][2]={{355,55},{445,55},{445,145},{355,145}};   //1st virus surrounding small circle
	int arr6[][2]={{470,245},{540,175},{610,245},{540,315}}; //2nd virus surrounding big circle
	int arr7[][2]={{495,200},{585,200},{585,290},{495,290}}; //2nd virus surrounding small circle
	
	for(int i=0;i<4;i++){
		delay(500);
		circle(arr4[i][0],arr4[i][1],7);
		circle(arr5[i][0],arr5[i][1],4);


		circle(arr6[i][0],arr6[i][1],7);
		circle(arr7[i][0],arr7[i][1],4);
		
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(arr4[i][0],arr4[i][1],WHITE);
		floodfill(arr5[i][0],arr5[i][1],WHITE);

		floodfill(arr6[i][0],arr6[i][1],WHITE);
		floodfill(arr7[i][0],arr7[i][1],WHITE);
	}
	
	for(int i=0;i<4;i++){
		setlinestyle(0, 0, 3);
		line(arr4[i][0],arr4[i][1],400,100);
		line(arr6[i][0],arr6[i][1],540,245);

		setlinestyle(0, 0, 2);
		line(arr5[i][0],arr5[i][1],400,100);
		line(arr7[i][0],arr7[i][1],540,245);
	}
	
	//form dotline using interpolation & putpixel()
	float X1[]={650,490,300,700,460,540,400};
	float Y1[]={270,330,100,200,50,150,200};
	float X2[]={850,450,120,900,560,650,350};
	float Y2[]={380,450,100,150,0,0,350};
	
	interpolation(X1,Y1,X2,Y2,7); 

	for(int no=0; no<20; no++){
	delay(50);
	setcolor(BLACK);
	circle(400,100,43);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(400,100,BLACK);	
	circle(540,245,43);
	floodfill(540,245,BLACK);
	delay(5);
	setcolor(WHITE);
	circle(400,100,43);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(400,100,WHITE);	
	circle(540,245,43);
	floodfill(540,245,WHITE);
	
	continue;
}
	printMsg();
	cleardevice();
	set++;
	
	}while(set<10);	
	getch();
	closegraph();
   return 0;
}
