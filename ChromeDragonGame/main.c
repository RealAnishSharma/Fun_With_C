#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>
#define kb if(kbhit()){keyx=get_code(); break;}
#define swc if(keyx==13){jump();}
#define sc score++;gotoxy(80,5);printf("SCORE:%d",score);gotoxy(80,4);printf("STARS:%d",stars);if(score>500) {qx=10;divo=10;}if(score>1000) {qx=5;divo=2;}
COORD coord={0,0};

int i,e=178,ai=33,aj=17,flag=1,dir=1,clk=0,stars=0,prev=3,pos=88;
int br,r,level=0,score=0,u=88,qx=14,divo=100,bar_rep,count;
clock_t ti;

static int get_code();
void gotoxy(int x,int y);
void delay(unsigned int mseconds);
void running_base();
void frame();
void jump();
void anim();
void barrier();
void barrier1();
void barrier2();
void player(int dir);
void info();

int main()
{
    char key;
    //info();
    system("color 5B");
    frame();
    player(1);
    running_base();
    getch();
    return 0;
}

delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

get_code()
{
    int ch=getch();
    if(ch==0||ch==224)
        ch=256+getch();
    return ch;
}

frame()
{
    int i;
    gotoxy(30,6);printf("%c",201);
    for(i=31;i<90;i++)
    {
    gotoxy(i,6);
    printf("%c",205);
    }
    gotoxy(89,6);
    printf("%c",187);
    for(i=7;i<20;i++)
    {
        gotoxy(30,i);
        printf("%c",186);
    }
        gotoxy(30,20);
        printf("%c",200);

    for(i=31;i<90;i++)
    {
        gotoxy(i,20);
        printf("%c",205);
    }

    for(i=7;i<20;i++)
    {
        gotoxy(89,i);
        printf("%c",186);
    }
    gotoxy(89,20);
    printf("%c",188);

}

info()
{
    printf("------------------------------\n");
    printf("The Chrome's DINOSAUR GAME\n");
    printf("------------------------------\n");
    printf("RULES\n1.Press Enter to JUMP.\n2.Save yourself from barriers.\n3.Just that simple buddy\nPress Enter to BEGIN or any other key to EXIT.");
    char key=getch();
    if(key==13){system("cls");}
    else exit(0);
}

player(int dir)
{
    gotoxy(ai,aj);printf("%c",153);
    gotoxy(ai,aj+1);printf("%c",219);

    if(aj!=17&&dir==0){
        gotoxy(ai,aj+2);printf(" ");
        gotoxy(ai,aj+3);printf(" ");
    }
    else{
        gotoxy(ai,aj-1);printf(" ");
        gotoxy(ai,aj-2);printf(" ");
    }

}

jump()
{
int k,p;
printf("\a");
{
    for(k=0;k<2;k++)
     {
        level=level+1;
        aj=aj-2;
        player(0);
        for(p=0;p<3;p++)
        {
            if(i==31) i=88;
            gotoxy(i,19);i--;
            printf("%c",e);
            if(r<=88) anim();

            delay(20);
            u=i;
            sc
            out();
        }


     }
     for(k=2;k>0;k--)
     {
        level=level-1;
        aj=aj+2;
        player(1);
        for(p=0;p<3;p++)
        {
            if(i==31) i=88;
            gotoxy(i,19);i--;
            printf("%c",e);
            if(r<=88) anim();
            delay(20);
            sc
            out();
        }

     }
}
pos=i;
running_base();
}


barrier()
{
  if(score<400)
    {bar_rep=1;barrier1();}
  else
    {bar_rep=2;barrier2();}
}

barrier1()
{
    r=88;br=176;
    if(i%2==0)system("color 3F");//printf("\a");
    gotoxy(r,17);printf("%c",br);
    gotoxy(r,18);printf("%c",br);
    count++;
}
barrier2()
{
    if(count%2==0) barrier1();
    else{
    r=88;br=219;
    if(i%2==0)system("color 3A");
    //printf("\a");
    gotoxy(r,17);printf("%c",br);
    gotoxy(r,18);printf("%c",br);
    gotoxy(r,19);printf("%c",br);
    count++;
}}


running_base()
{
    char keyx;
    gotoxy(88,19);
    for(i=pos;i>30;i--)
    {
        kb
        gotoxy(i,19);
        delay(15);
        printf("%c",e);
        delay(15);
        if(i==31){i=89;if(e==178) e=177; else e=178;}

        //if(i==31){i=89;if(e==178) e=177; else e=178;}


        ti=clock();
        if((ti%divo==0||ti%5==0)&&flag==1){barrier();flag=0;}

        if(r<=88)anim();
        sc
        out();
    }
    swc
}




anim()
{
        if(r<=88&&r>31){
        gotoxy(r,16);printf(" ");
        gotoxy(r,17);printf(" ");
        gotoxy(r,18);printf(" ");}
        r--;

        if(r>31){
        if(bar_rep==2){gotoxy(r,16);printf("%c",br);}
        gotoxy(r,17);printf("%c",br);
        gotoxy(r,18);printf("%c",br);
        }
        else {flag=1;}
        out();
        delay(qx);
}


out()
{
    int t=10;
    if(r==33)
    {
    if(level==0||(level==1&&bar_rep==2)){
      gotoxy(ai,aj);printf("%c",237);
      gotoxy(ai,aj+1);printf("%c",219);

      {gotoxy(36,12);delay(100);system("COLOR 4F");printf("O U T");delay(100);system("COLOR F4");}
      system("COLOR 0F");
      gotoxy(0,2);
      choice();
      return;
      }

      else stars++;sc
    }
}

choice()
{
    char key;
    gotoxy(30,22);
    printf("Press y to continue..Else go away pressing any other key.");
    key=getch();
    if(key=='y'||key=='Y'){system("cls");ai=33;aj=17;stars=0;score=0;pos=88;main();}
    else exit(1);
}

