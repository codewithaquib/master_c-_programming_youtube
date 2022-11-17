//header files...
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function prototypes...
void sound();
void home();
void how_to_play();
void board();
void input();
int random_num_gen();

//global variables...
int global = 0;
int move = 0;
int rand_arr[100];

//function definitions follow...

//function for music in home...
void Sound()
{	sound(240);
	delay(500);
	sound(270);
	delay(500);
	sound(300);
	delay(500);
	sound(320);
	delay(500);
	sound(360);
	delay(500);
	sound(400);
	delay(500);
	sound(450);
	delay(500);
	sound(480);
	delay(500);
	nosound();
}

//function for home
void home()
{
Sound();
//to print snakes & ladders
	setbkcolor(RED);
	setcolor(YELLOW);
	settextstyle(8,0,7);
	outtextxy(25,50,"SNAKES");
	outtextxy(275,150,"&");
	outtextxy(325,250,"LADDERS");
//to draw the snake...
	setcolor(CYAN);
	setlinestyle(SOLID_LINE,1,2);
	arc(175,360,90,200,60);
	circle(167,201,3);
	line(166,204,163,207);
	setlinestyle(SOLID_LINE,1,3);
	arc(170,250,270,90,50);
	putpixel(167,201,WHITE);
//to draw ladder...
	setcolor(GREEN);
	line(390,220,390,100);
	line(370,220,370,100);
	line(370,115,390,115);
	line(370,155,390,155);
	line(370,195,390,195);
getch();
cleardevice();
}

//function for displaying the instructions...
void how_to_play()
{
setbkcolor(BLACK);
   cout<<endl<<" How to play the game.....";
   cout<<endl<<"________________________________________________________________________________";
   cout<<endl<<"1. Press the Spacebar to Roll The Die.";
   cout<<endl<<"2. When Die is rolled,a number is randomly generated.";
   cout<<endl<<"3. You Piece will move those much steps.";
   cout<<endl<<"4. Rest is all LUCK.If you stop on a Snake's mouth,You will be ";
   cout<<endl<<"   thrown down to its tail, i.e. you will be eaten by him.";
   cout<<endl<<"5. If you stop on a ladder,You will be Promoted upwards.";
   cout<<endl<<"6. The first person to reach '100' wins.";
   cout<<endl<<"7. You can press 'e' or 'E' to QUIT the game at any time.";
   cout<<endl<<endl<<"\n\n\n\n\n\n  NOTE : YOUR PROGRESS WILL NOT BE SAVED ";
getch();
cleardevice();
}

//function for drawing the board...
void board()
{
   int gd = DETECT, gm;
   int l,r,t,b;
   initgraph(&gd,&gm, "c:/turboc3/bgi");
   setviewport(10,10,200,200,0);
   setbkcolor(DARKGRAY);

//code to generate checkerboard
   int counter1 = 10,x1 = 0,x2 = 40,y1 = 40,y2 = 80;
   setcolor(CYAN);
   while(counter1 >0)
   {
    int counter2 = 10;
	while(counter2 > 0)
	{
	   rectangle(x1,y1,x2,y2);
	   x1+=40; x2 +=40;counter2--;
	}
    counter1--;
    x1= 0; x2=40;y1+=40;y2+=40;
    }

    //code to generate grid numbers
       //left to right
	int num = 1;
	x1 = 0,x2 = 40,y1 = 400,y2 = 440;
	 counter1 = 5;
	 char str[3];
	     setcolor(GREEN);
	     while (counter1 > 0)
	     {
	       int counter2 = 10;
		while(counter2 > 0)
		{
		sprintf(str,"%d",num);
		outtextxy(((x1)+(x2))/2,(y1+y2)/2,str);
		x1+=40; x2 +=40;counter2--;
		num++;
		}
	     counter1--;
	     x1= 0; x2=40;y1-=80;y2-=80;num+=10;
	     }
       //right to left
	num = 11;
	x1 =360,x2 = 400,y1 = 320,y2 = 440;
	  counter1 = 5;
	   while (counter1 > 0)
	   {
	    int counter2 = 10;
	    while(counter2 > 0)
	      {
		sprintf(str,"%d",num);
		outtextxy(((x1)+(x2))/2,(y1+y2)/2,str);
		x1-=40; x2 -=40;counter2--;
		num++;
	      }
	   counter1--;
	    x1= 360; x2=400;y1-=80;y2-=80;num+=10;
	   }

//code to draw ladders...
//ladder 1
  setcolor(YELLOW);
  setlinestyle(SOLID_LINE,0,2);
  line(180,255,295,405);
  line(195,250,315,405);
  int count_leg = 3, a1 = 290, a2 = 300, b1 = 400, b2 = 390;
    while ( count_leg > 0 )
     {
       a1-=30,a2-=30,b1-=40,b2-=40;
       line(a1,b1,a2,b2);
       count_leg--;
     }

//ladder 2
  setcolor(YELLOW);
  setlinestyle(SOLID_LINE,0,2);
  line(64,190,24,95);
  line(44,190,4,95);
  line(36,125,18,128);
  line(52,162,33,165);

//ladder 3
  line(45,380,294,50);
  line(70,390,317,55);
  line(240,120,255,140);
  line(187,192,202,212);
  line(120,280,136,300);

//ladder 4
  line(390,220,390,100);
  line(370,220,370,100);
  line(370,115,390,115);
  line(370,155,390,155);
  line(370,195,390,195);

//ladder 5
  line(335,315,168,150);
  line(357,303,193,138);
  line(230,211,247,192);
  line(274,255,289,236);
  line(312,290,325,273);

//code to draw snakes
//snake 1
  setcolor(RED);
  setlinestyle(SOLID_LINE,0,3);
  arc(270,268,330,40,20);
  arc(334,355,120,182,90);
  setlinestyle(SOLID_LINE,0,2);
  arc(320,360,179,230,75);
  circle(288,254,3);
  putpixel(288,254,YELLOW);
  line(290,254,293,252);

//snake 2
  setlinestyle(SOLID_LINE,1,3);
  arc(165,100,160,240,120);
  setlinestyle(SOLID_LINE,1,2);
  arc(33,300,320,65,120);
  circle(55,58,3);
  putpixel(55,58,YELLOW);
  line(58,58,61,58);

//snake 3
  setlinestyle(SOLID_LINE,1,2);
  arc(65,410,90,200,60);
  circle(60,254,3);
  line(60,256,62,260);
  setlinestyle(SOLID_LINE,1,3);
  arc(60,300,270,90,50);
  putpixel(60,254,YELLOW);

//snake 4
  setlinestyle(SOLID_LINE,1,2);
  arc(340,140,90,180,40);
  circle(380,57,3);
  putpixel(380,57,YELLOW);
  line(383,58,385,58);
  setlinestyle(SOLID_LINE,1,3);
  arc(340,60,260,0,40);

//snake 5
  setlinestyle(SOLID_LINE,1,3);
  arc(190,180,0,90,90);
  setlinestyle(SOLID_LINE,1,2);
  arc(370,180,180,270,90);
  circle(188,92,3);
  putpixel(188,92,YELLOW);
  line(185,92,182,92);

//code to display the controls...
setcolor(YELLOW);
outtextxy(480,40,"CONTROLS : ");
outtextxy(420,60,"SPACE - Roll The Die");
outtextxy(420,80,"E - Exit");

//calling function for taking input...
input();

getch();
closegraph();
}

//function for generating random number...
void rand_generator()
{
randomize();
for(int p = 0; p <= 100; p++)
rand_arr[p] = rand() % 6 + 1;
}

//function for taking the input...
void input()
{
static int posx[] = {	20,60,100,140,180,220,260,300,340,380,
			380,340,300,260,220,180,140,100,60,20,
			20,60,100,140,180,220,260,300,340,380,
			380,340,300,260,220,180,140,100,60,20,
			20,60,100,140,180,220,260,300,340,380,
			380,340,300,260,220,180,140,100,60,20,
			20,60,100,140,180,220,260,300,340,380,
			380,340,300,260,220,180,140,100,60,20,
			20,60,100,140,180,220,260,300,340,380,
			380,340,300,260,220,180,140,100,60,20,
		    };
static int posy[] = {	420,420,420,420,420,420,420,420,420,420,
			380,380,380,380,380,380,380,380,380,380,
			340,340,340,340,340,340,340,340,340,340,
			300,300,300,300,300,300,300,300,300,300,
			260,260,260,260,260,260,260,260,260,260,
			220,220,220,220,220,220,220,220,220,220,
			180,180,180,180,180,180,180,180,180,180,
			140,140,140,140,140,140,140,140,140,140,
			100,100,100,100,100,100,100,100,100,100,
			 60, 60, 60, 60, 60, 60, 60, 60, 60, 60
		    };

char inp1 = 'o';
int tp;
char str1[1];
static int index = 0;
 while(inp1 != 'e' || inp1 != 'E')
  {
   inp1 = getche();
	if(inp1 == ' ')
	  {
	   global = rand_arr[index];
	   index++;
	sprintf(str1,"%d",global);
	settextstyle(3,0,3);
	outtextxy(420,120,"The die shows : ");
	outtextxy(440,150,str1);
	  delay(3000);
	  move = move + global;

//code to move the piece as per snakes and ladders...
	   if(move == 8)
	     {
	       pieslice(posx[44],posy[44],0,360,5);
	       move = 45;
	     }
	   else if(move == 19)
	     {
	       pieslice(posx[92],posy[92],0,360,5);
	       move = 93;
	     }
	   else if(move == 32)
	     {
	       pieslice(posx[75],posy[75],0,360,5);
	       move = 76;
	     }
	   else if(move == 42)
	     {
	       pieslice(posx[0],posy[0],0,360,5);
	       move = 1;
	     }
	   else if(move == 48)
	     {
	       pieslice(posx[6],posy[6],0,360,5);
	       move = 7;
	     }
	   else if(move == 51)
	     {
	       pieslice(posx[89],posy[89],0,360,5);
	       move = 90;
	     }
	   else if(move == 62)
	     {
	       pieslice(posx[80],posy[80],0,360,5);
	       move = 81;
	     }
	   else if(move == 85)
	     {
	       pieslice(posx[49],posy[49],0,360,5);
	       move = 50;
	     }
	   else if(move == 91)
	     {
	       pieslice(posx[72],posy[72],0,360,5);
	       move = 73;
	     }
	   else if(move == 99)
	     {
	       pieslice(posx[16],posy[16],0,360,5);
	       move = 17;
	     }
	   else
	     {
	       pieslice(posx[move-1],posy[move-1],0,360,5);
	     delay(1000);
	     }
clearviewport();
closegraph();
board();
	  }
	else if(inp1 == 'E' || inp1 == 'e')
	  {
	cleardevice();
	settextstyle(1,0,0);
	outtextxy(150,120,"Are you sure ");
	outtextxy(170,150,"want to quit??(y/n)");
	char choice = getche();
		if(choice == 'y'|| choice == 'Y')
		{exit(0);}
		else if(choice=='n' || choice == 'N')
		{
		outtextxy(150,200,"Press any key to continue..");
		char temp = getche();
			if(temp)
			{
			cleardevice();
			board();
			}
		}
	 }
    }
}

//main function...
main()
{
int gd = DETECT, gm;
initgraph(&gd,&gm, "c:/turboc3/bgi");
rand_generator();
home();
how_to_play();
board();



getch();
}
