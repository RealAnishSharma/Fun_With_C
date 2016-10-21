#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

#define kb if(kbhit()){keyx=get_code(); break;}
#define swc switch(keyx){case 256+80:down_key(i,j);break;case 256+75:left_key(i,j);break;case 256+72:up_key(i,j);break;case 256+77:right_key(i,j);break; default:NULL;}

COORD coord={0,0};
void gotoxy(int x,int y);
static int get_code();
void print_board();
void delay();
void right_key(int x,int y);
void left_key(int x,int y);
void up_key(int x,int y);
void down_key(int x,int y);
void bend(int i,int j);
void food();
void info();
void color();

char dir[2];
int len=3,m=0,n=0,speed=50000000,score=0;
void cf(int p,int q){if((p==m)&&(q==n)) {color();food();speed=speed-5000000;score++;gotoxy(20,20);printf("%d",score);}}


int main()
{
   char abc[100];
   a25:system("cls");
   system("COLOR 7");
    info();
    getch();
    system("cls");
    printf("Enter your name:\n");
    gets(abc);
    printf("WELCOME %s",abc);
    load();
    system("cls");
    dir[0]='x';dir[1]='x';
    print_board();
    food();
    right_key(3,10);
    gotoxy(2,22);
    printf("%s gets %d score.\n  If you Wanna REPPLAY...Press ENTER\n  If you Wanna exit....Press other key.",abc,score);
    char u;
    u=getch();
    if(u==13) goto a25;

    getch();

}

print_board()
{
    int i;
    printf("  %c",205);
    for(i=0;i<45;i++) printf("%c",205);
    printf("\n\t     %c%c%c%c%c%cSNAKY SNAKE%c%c%c%c%c%c\n",186,186,186,186,186,186,186,186,186,186,186,186);
    printf("  %c",205);
    for(i=0;i<45;i++) printf("%c",205);
    printf("\n ");
    for(i=0;i<15;i++) printf("%c\t\t\t\t\t\t%c\n ",186,186);
    printf(" %c",205);
    for(i=0;i<45;i++) printf("%c",205);
    gotoxy(14,20);printf("SCORE");
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

delay(){int k;for(k=0;k<speed;k++);}

right_key(x,y)
{
    dir[1]='r';
    int i=x,j=y,keyx,k;
    bend(i,j);
    if(dir[0]=='l'){x=x+1;}
    if(dir[0]=='d') {j=j+1;}
    for(i=x;i<=47;i++)
    {
        kb
        //food(flg);
        delay();

        gotoxy(i-1,j);printf(" ");

        for(k=0;k<len;k++)
        {gotoxy(i+k,j);cf(i+k,j);gotoxy(i+k,j);printf("%c",'*');}


        if(i==46) {gotoxy(2,20);printf("OUT\n");return 0;}
    }

    dir[0]='r';
    swc
}

left_key(x,y)
{
    int flag=0;

    dir[1]='l';
    //if(dir[0]=='d' || dir[0]=='u'){flag=2;}
    int i=x,j=y,keyx,k;
    bend(i,j);
    if(dir[0]=='d') {x=x-2;j=j+1;}
    if(dir[0]=='r'||dir[0]=='u'){x=x-2;}
    for(i=x;i>=1;i--)
    {
        kb
       // food(flg);
        delay();

        if(i!=1)gotoxy(i+3,j);printf(" ");
        for(k=0;k<len;k++)
        {gotoxy(i+k,j);cf(i+k,j);gotoxy(i+k,j);printf("%c",'*');}

        if(i==1){gotoxy(2,20);printf("OUT\n");return 0;}

    }
    dir[0]='l';
    swc
}

down_key(x,y)
{
    dir[1]='d';
    int i=x,j=y,k,keyx;

    bend(i,j);
    if(dir[0]=='r') i=i+1;
    if(dir[0]=='l') i=i+1;
    for(j=y;j<=17;j++)
    {
        kb
        delay();
        if(j!=3){gotoxy(i,j-1);printf(" ");}

        for(k=0;k<len;k++)
        {gotoxy(i,j+k);cf(i,j+k);gotoxy(i,j+k);printf("%c ",'*');}


        if(j==16){gotoxy(2,20);printf("OUT\n");return;}
    }
    dir[0]='d';
    swc
}


up_key(x,y)
{
    dir[1]='u';

    int i=x,j=y,k,keyx;
    bend(i,j);

    if(dir[0]=='l') i=i+1;
    if(dir[0]=='r') i=i+1;

    for(j=y;j>=4;j--)
    {
        kb
        //food(flg);
        delay();
        if(j!=3){gotoxy(i,j+1);printf(" ");}

        for(k=0;k<len;k++)
        {gotoxy(i,j-k);cf(i,j-k);gotoxy(i,j-k);printf("%c",'*');}

        if(j==4){gotoxy(2,20);printf("OUT\n");return;}
    }
    dir[0]='u';
    swc
}

bend(int i,int j)
{
    int k;
    if(dir[0]=='x'||dir[1]=='x') return;
    else if(dir[0]=='r'&&dir[1]=='d')
    {

    for(k=1;k<len;k++)
    {
        gotoxy(i+k-2,j);printf(" ");
        gotoxy(i+1,j+k);printf("%c",'*');
        delay();
    }
    return;
    }
    else if(dir[0]=='r'&& dir[1]=='u')
    {

    for(k=1;k<len;k++)
    {
        gotoxy(i+k-2,j);printf(" ");
        gotoxy(i+1,j-k);printf("%c",'*');
        delay();
    }
    return;
    }
    else if(dir[0]=='l' && dir[1]=='d')
    {

     for(k=1;k<len;k++)
     {
        gotoxy(i-k+4,j);printf(" ");
        gotoxy(i+1,j+k);printf("%c",'*');
        delay();
     }
     return;
    }
    else if(dir[0]=='l' && dir[1]=='u')
    {

      for(k=1;k<len;k++)
      {
        gotoxy(i+4-k,j);printf(" ");
        gotoxy(i+1,j-k);printf("%c",'*');
        delay();
      }
      return;
    }
    else if(dir[0]=='d' && dir[1]=='r')
    {

        for(k=1;k<len;k++)
        {
        gotoxy(i,j+k-2);printf(" ");
        gotoxy(i+k,j+1);printf("%c",'*');
        delay();
        }
        return;
    }

    else if(dir[0]=='d' && dir[1]=='l')
    {

        for(k=1;k<len;k++)
        {
        gotoxy(i,j+k-2);printf(" ");
        gotoxy(i-k,j+1);printf("%c",'*');
        delay();
        }
        return;
    }

    else if(dir[0]=='u' && dir[1]=='l')
    {
        gotoxy(i,j-1);printf(" ");
        gotoxy(i-1,j);printf("%c",'*');
        delay();
        gotoxy(i,j+1);printf(" ");
        gotoxy(i-2,j);printf("%c",'*');
        return;
    }

    else if(dir[0]=='u' && dir[1]=='r')
    {
        gotoxy(i,j-1);printf(" ");
        gotoxy(i+1,j);printf("%c",'*');
        delay();
        gotoxy(i,j+1);printf(" ");
        gotoxy(i+2,j);printf("%c",'*');
        return;
    }
}

void food()
{
    while(1){
    m=rand()%47;
    n=rand()%17;

    if(m<=2||n<=3) {m=m+5;n=n+5;}
    if(n+3>=46) {n=n-4;}
    break;
    }
    gotoxy(m,n);
    printf("%c",248);
}

info()
{
    printf("S N A K E  G A M E\n\nRULES:\n--------\n");
    printf("1.Use Arrow keys to move snake.\n2.Eat FRUITS to gain score.\n3.Don't kill your self by touching boundary.\n4.With each fruit that snake eats it gains speed");;
    printf("\nEnter to start");
}

load()
{
    int q;
    gotoxy(25,15);
    printf("LOADING...");
    gotoxy(25,16);
    for(q=0;q<20;q++){
        printf("%c",177);
        delay();delay();}
}

color()
{
    switch(score)
    {
        case 0: system("COLOR 3");break;
        case 1: system("COLOR 6");break;
        case 2: system("COLOR 7");break;
        case 3: system("COLOR c");break;
        case 4: system("COLOR d");break;
        case 5: system("COLOR e");break;
        case 6: system("COLOR 7");break;
        case 7: system("COLOR 8");break;
        case 8: system("COLOR 9");break;
        case 9: system("COLOR A");break;
    }
}

