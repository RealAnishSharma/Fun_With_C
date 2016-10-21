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

void compTurn(int count,char sym,char cosym)
{
    int i,j,flag=0,duf=0;
    if(count==1)
    {
        if(A[1][1]=='-') {A[1][1]=cosym;system("cls");flag=0;display();return;}
        else{
        while(!flag){
        int x=rand()%3;
        int y=rand()%3;
        if(A[x][y]=='-'){A[x][y]=cosym;system("cls");flag=0;display();return;}}
    }}
    else
    {
        //IF COMP IS ABOUT TO WIN,LET IT WIN
        if(A[0][0]==cosym&&A[1][1]==cosym && A[2][2]=='-'){A[2][2]=cosym;system("cls");display();return;}
        else if(A[0][0]==cosym&&A[2][2]==cosym && A[1][1]=='-'){A[1][1]=cosym;system("cls");display();return;}
        else if(A[1][1]==cosym&&A[2][2]==cosym && A[0][0]=='-'){A[0][0]=cosym;system("cls");display();return;}
        else if(A[0][2]==cosym&&A[1][1]==cosym && A[2][0]=='-'){A[2][0]=cosym;system("cls");display();return;}
        else if(A[2][0]==cosym&&A[1][1]==cosym && A[0][2]=='-'){A[0][2]=cosym;system("cls");display();return;}
        else if(A[0][2]==cosym&&A[2][0]==cosym && A[1][1]=='-'){A[1][1]=cosym;system("cls");display();return;}

        for(i=0;i<3;i++)
        {
            if(A[i][0]==cosym && A[i][1]==cosym && A[i][2]=='-') {A[i][2]=cosym;system("cls");display();return;}
            else if(A[i][0]==cosym && A[i][2]==cosym &&A[i][1]=='-') {A[i][1]=cosym;system("cls");display();return;}
            else if(A[i][1]==cosym && A[i][2]==cosym && A[i][0]=='-') {A[i][0]=cosym;system("cls");display();return;}
        }
        for(j=0;j<3;j++)
        {
            if(A[0][j]==cosym && A[1][j]==cosym && A[2][j]=='-') {A[2][j]=cosym;system("cls");display();return;}
            else if(A[0][j]==cosym && A[2][j]==cosym && A[1][j]=='-') {A[1][j]=cosym;system("cls");display();return;}
            else if(A[1][j]==cosym && A[2][j]==cosym && A[0][j]=='-') {A[0][j]=cosym;system("cls");display();return;}
        }
        ///////IF USER IS ABOUT TO WIN,MAKE USER LOOSE
        if(A[0][0]==sym&&A[1][1]==sym && A[2][2]=='-'){A[2][2]='O';system("cls");display();return;}
        else if(A[0][0]==sym&&A[2][2]==sym && A[1][1]=='-'){A[1][1]=cosym;system("cls");display();return;}
        else if(A[1][1]==sym&&A[2][2]==sym && A[0][0]=='-'){A[0][0]=cosym;system("cls");display();return;}
        else if(A[0][2]==sym&&A[1][1]==sym && A[2][0]=='-'){A[2][0]=cosym;system("cls");display();return;}
        else if(A[2][0]==sym&&A[1][1]==sym && A[0][2]=='-'){A[0][2]=cosym;system("cls");display();return;}
        else if(A[0][2]==sym&&A[2][0]==sym && A[1][1]=='-'){A[1][1]=cosym;system("cls");display();return;}


        for(i=0;i<3;i++)
        {
            if(A[i][0]==sym && A[i][1]==sym && A[i][2]=='-') {A[i][2]=cosym;system("cls");display();return;}
            else if(A[i][0]==sym && A[i][2]==sym &&A[i][1]=='-') {A[i][1]=cosym;system("cls");display();return;}
            else if(A[i][1]==sym && A[i][2]==sym && A[i][0]=='-') {A[i][0]=cosym;system("cls");display();return;}
        }
        for(j=0;j<3;j++)
        {
            if(A[0][j]==sym && A[1][j]==sym && A[2][j]=='-') {A[2][j]=cosym;system("cls");display();return;}
            else if(A[0][j]==sym && A[2][j]==sym && A[1][j]=='-') {A[1][j]=cosym;system("cls");display();return;}
            else if(A[1][j]==sym && A[2][j]==sym && A[0][j]=='-') {A[0][j]=cosym;system("cls");display();return;}
        }

        if(A[0][0]==sym&&A[1][1]==cosym&&A[2][2]==sym&&A[0][1]=='-'&&duf==0){A[0][1]=cosym;duf=1;system("cls");display();return;}
        else if(A[0][0]==sym&&A[1][1]==cosym&&A[2][2]==sym&&A[1][0]=='-'&&duf==0){A[1][0]=cosym;duf=1;system("cls");display();return;}
        else if(A[0][0]==sym&&A[1][1]==cosym&&A[2][2]==sym&&A[1][2]=='-'&&duf==0){A[1][2]=cosym;duf=1;system("cls");display();return;}
        else if(A[0][0]==sym&&A[1][1]==cosym&&A[2][2]==sym&&A[2][1]=='-'&&duf==0){A[2][1]=cosym;duf=1;system("cls");display();return;}
        else if(A[0][2]==sym&&A[1][1]==cosym&&A[2][0]==sym&&A[0][1]=='-'&&duf==0){A[0][1]=cosym;duf=1;system("cls");display();return;}
        else if(A[0][2]==sym&&A[1][1]==cosym&&A[2][0]==sym&&A[1][0]=='-'&&duf==0){A[1][0]=cosym;duf=1;system("cls");display();return;}
        else if(A[0][2]==sym&&A[1][1]==cosym&&A[2][0]==sym&&A[1][2]=='-'&&duf==0){A[1][2]=cosym;duf=1;system("cls");display();return;}
        else if(A[0][2]==sym&&A[1][1]==cosym&&A[2][0]==sym&&A[2][1]=='-'&&duf==0){A[2][1]=cosym;duf=1;system("cls");display();return;}


        //if nothing happens so far
        while(!flag){
        int x=rand()%3;
        int y=rand()%3;
        if(A[x][y]=='-'){A[x][y]=cosym;system("cls");display();flag=1;return;}

    }

}
}

void getinp(int x,int y,char sym,char cosym)
{
    char brf=A[0][0];
    while(1){
    char key=getch();
    while(key!=13)
    {
    if(key=='K')
    {
     A[y][x]=brf;
     if(x>0) x--;else x=2;
     brf=A[y][x];
     if(A[y][x]=='-')A[y][x]='|';
     else A[y][x]='!';
     system("cls");display();
    }

    else if(key=='P')
    {
     A[y][x]=brf;
     if(y<2) y++;else y=0;
     brf=A[y][x];
     if(A[y][x]=='-')A[y][x]='|';
     else A[y][x]='!';
     system("cls");display();
    }

    else if(key=='H')
    {
     A[y][x]=brf;
     if(y>0) y--;else y=2;
     brf=A[y][x];
     if(A[y][x]=='-')A[y][x]='|';
     else A[y][x]='!';
     system("cls");display();
    }

    else if (key=='M')
    {
     A[y][x]=brf;
     if(x<2) x++;else x=0;
     brf=A[y][x];
     if(A[y][x]=='-')A[y][x]='|';
     else A[y][x]='!';
     system("cls");display();
    }

    key=getch();
    }
    if(A[y][x]=='|')
    {A[y][x]=sym;system("cls");display();return;}
    else {printf("This position is already filled.\nChoose an unfillled position");continue;}
    }
}

int main()
{

    int a,count=0,x=0,y=0;
    char name[30],sym,cosym;
    memset(A,'-',9);
    printf("Name of User\n");
    gets(name);
    system("cls");
    printf("welcome %s\n",name);
    printf("choose your symbol:X or O\n");
    scanf("%c",&sym);
    if(sym=='X') cosym='O';
    else cosym='X';
    system("cls");
    display();


    while(1)
    {
        printf("\n===================\n");
        printf("%s :",name);
        getinp(x,y,sym,cosym);count++;
        if(count==9)
        {printf("\n-- -- --Tie-- -- --\n");break;}
        compTurn(count,sym,cosym);count++;

        char k=check();
        if(k==sym){printf("\n-- -- -- -- -- --\n%s WINS\n-- -- -- -- -- --\n",name);break;}
        else if(k==cosym){printf("\n-- -- -- -- -- --\nComputer WINS\n-- -- -- -- -- --\n");break;}
        else continue;
    }
return 0;
}



