#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char A[3][3];

char check()
{
   if (A[0][0]=='X'&&A[0][1]=='X'&&A[0][2]=='X') return 'X';
   if (A[1][0]=='X'&&A[1][1]=='X'&&A[1][2]=='X') return 'X';
   if (A[2][0]=='X'&&A[2][1]=='X'&&A[2][2]=='X') return 'X';
   if (A[0][0]=='X'&&A[1][0]=='X'&&A[2][0]=='X') return 'X';
   if (A[0][1]=='X'&&A[1][1]=='X'&&A[2][1]=='X') return 'X';
   if (A[0][2]=='X'&&A[1][2]=='X'&&A[2][2]=='X') return 'X';
   if (A[0][0]=='X'&&A[1][1]=='X'&&A[2][2]=='X') return 'X';
   if (A[2][0]=='X'&&A[1][1]=='X'&&A[0][2]=='X') return 'X';
   if (A[0][0]=='O'&&A[0][1]=='O'&&A[0][2]=='O') return 'O';
   if (A[1][0]=='O'&&A[1][1]=='O'&&A[1][2]=='O') return 'O';
   if (A[2][0]=='O'&&A[2][1]=='O'&&A[2][2]=='O') return 'O';
   if (A[0][0]=='O'&&A[1][0]=='O'&&A[2][0]=='O') return 'O';
   if (A[0][1]=='O'&&A[1][1]=='O'&&A[2][1]=='O') return 'O';
   if (A[0][2]=='O'&&A[1][2]=='O'&&A[2][2]=='O') return 'O';
   if (A[0][0]=='O'&&A[1][1]=='O'&&A[2][2]=='O') return 'O';
   if (A[2][0]=='O'&&A[1][1]=='O'&&A[0][2]=='O') return 'O';

    return 'Z';
}

void display()
{
    int i,j;
    printf("===================\n");
    printf("   Tic Tac Toe\n");
    printf("===================\n\n");
    for(i=0;i<3;i++)
    {
        printf(" ");
        for(j=0;j<3;j++)
            printf("%c\t",A[i][j]);
        printf("\n");
    }
}

void getinp(int x,int y,int user,char sym,char cosym)
{
    char brf=A[0][0];
    while(1){
    char key=getch();
    while(key!=13)
    {
    A[y][x]=brf;
    if(key=='K')
    {
     if(x>0) x--;else x=2;
     brf=A[y][x];
     if(A[y][x]=='-')A[y][x]='|';
     else A[y][x]='!';
    }

    else if(key=='P')
    {
     if(y<2) y++;else y=0;
     brf=A[y][x];
     if(A[y][x]=='-')A[y][x]='|';
     else A[y][x]='!';
    }

    else if(key=='H')
    {
     if(y>0) y--;else y=2;
     brf=A[y][x];
     if(A[y][x]=='-')A[y][x]='|';
     else A[y][x]='!';
    }

    else if (key=='M')
    {
     if(x<2) x++;else x=0;
     brf=A[y][x];
     if(A[y][x]=='-')A[y][x]='|';
     else A[y][x]='!';
    }
    system("cls");display();
    key=getch();
    }
    if(A[y][x]=='|')
    {
        if(user==1)A[y][x]=sym;
        else A[y][x]=cosym;
        system("cls");display();return;
    }
    else {printf("This position is already filled.\nChoose an unfillled position");continue;}
    }
}

int main()
{
    int a,count=0,x=0,y=0,user=1;
    char name1[50],name2[50],sym,cosym;
    memset(A,'-',9);
    printf("Name of user 1:");
    gets(name1);
    printf("Name of user 2:");
    gets(name2);
    system("cls");
    printf("%s choose your symbol: X or O\n",name1);
    scanf("%c",&sym);
    if(sym=='X') cosym='O';
    else cosym='X';
    printf("%s your symbol is \n%c\n\n",name2,cosym);
    printf("Enter to begin");
    getch();
    system("cls");
    display();
    while(count!=9)
    {
        if(user==1)
        printf("%s:",name1);
        else
        printf("%s:",name2);
        getinp(x,y,user,sym,cosym);

        count++;
        if(user==1) user=2;
        else user=1;

        char k=check();
        if(k==sym){printf("\n-- -- -- -- --\n%s WINS\n-- -- -- -- --\n",name1);break;}
        else if(k==cosym){printf("\n-- -- -- -- --%s WINS\n-- -- -- -- --\n",name2);break;}
        else continue;
    }
return 0;

}

/*
void getinp(int x,int y,int user)
{
    int m,n;
    char prs,key=getch();
    while(key!=13)
    {
    m=y;n=x;prs=A[m][n];
    if(prs=='|'){prs='-';}
    if(key=='a')
    {if(x>0) x--;else x=2;if(A[y][x]=='-')A[y][x]='|';A[m][n]=prs;system("cls");display();}
    else if(key=='s')
    {if(y<2) y++;else y=0;if(A[y][x]=='-')A[y][x]='|';A[m][n]=prs;system("cls");display();}
    else if(key=='w')
    {if(y>0) y--;else y=2;if(A[y][x]=='-')A[y][x]='|';A[m][n]=prs;system("cls");display();}
    else if (key=='d')
    {if(x<2) x++;else x=0;if(A[y][x]=='-')A[y][x]='|';A[m][n]=prs;system("cls");display();}
    else printf("\nInvalid key..retry");
    key=getch();
    }
    if(user==1)
    {A[y][x]='X';system("cls");display();}
    else
    {A[y][x]='O';system("cls");display();}
}*/
