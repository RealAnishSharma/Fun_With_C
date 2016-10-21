//rat in a maze problem
#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//#define N 12
int N=15,p;
#define ln  printf(" ");for(i=0;i<N*3;i++)printf("%c",205);printf("\n");

COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void printMaze(int maze[N][N])
{
    int i,j,flag=0;
    ln
    for(i=0;i<(N/2)-1;i++) printf("   ");

    printf("RAT_MAZE\n");
    ln
    for(i=0;i<N;i++)
    {
        //if(i==0) printf("%c",201);
        printf("%c",186);
        for(j=0;j<N;j++)
            if(maze[i][j]==0) printf("%c%c%c",178,178,178);
            else printf("   ");

            printf("%c\n",186);
    }
    ln
}

bool check(int maze[N][N],int x,int y)
{
    if(x<N&&x>=0&&y>=0&&y<N&&maze[x][y]==1) return true;
    return false;
}


bool ratHelp(int maze[N][N],int i,int j)
{
    maze[i][j]=2;
    //////////////////////////
    Sleep(79);
    gotoxy(2+3*(j),i+3);
    printf("%c",153);
    //////////////////////////

    if(i==N-1&&j==N-1)
    return true;

    if(check(maze,i,j+1))
        if(ratHelp(maze,i,j+1)) return true;

    if(check(maze,i+1,j))
        if(ratHelp(maze,i+1,j)) return true;

    if(check(maze,i,j-1))
        if(ratHelp(maze,i,j-1)) return true;

    if(check(maze,i-1,j))
        if(ratHelp(maze,i-1,j)) return true;

        maze[i][j]=1;
        Sleep(79);
        gotoxy(1+3*(j),i+3);
        printf("  ");
        return false;
}

void rat(int maze[N][N],int i,int j)
{

    if(!ratHelp(maze,i,j))
    {
     gotoxy(0,N+3);ln
     for(i=0;i<(N/2)-1;i++) printf("   ");
     printf("No solution\n");ln
    }
     else
    {
     gotoxy(0,N+3);ln
     for(i=0;i<(N/2)-1;i++) printf("   ");
     printf("Solution Found\n");ln
    }

}

int main()
{
/*

    printf("Enter the size of maze\n");
    scanf("%d",&N);
    printf("If you want a \n1.Randomly generated maze,Enter 1\n2.Create a maze, Enter 2\n");
    scanf("%d",&p);

    int maze[N][N];
    system("cls");


    int i,j;
    for(i=0;i<N;i++)
    for(j=0;j<N;j++)
        if(p==1)maze[i][j]=rand()%2;
        else if(p==2) scanf("%d",&maze[i][j]);

    //if(p==1){printf("Destination Please:");scanf("%d%d",&xx,&yy);maze[xx][yy]=1;}

*/




 int maze[15][15]={{1,1,1,1,1,1,1,0,1,0,0,0,0,0,0},
                   {0,0,0,1,0,0,1,1,1,1,1,1,1,1,1},
                   {0,0,0,1,0,0,0,0,0,0,0,0,0,1,1},
                   {0,1,1,1,0,0,1,1,1,1,1,1,0,0,1},
                   {0,1,1,1,0,0,1,0,0,0,0,1,0,1,1},
                   {0,1,0,0,0,0,1,1,0,0,1,1,0,1,0},
                   {0,1,1,1,1,1,1,1,0,0,1,0,1,1,0},
                   {0,1,0,0,0,0,0,0,1,0,1,0,0,0,0},
                   {0,1,1,1,1,1,1,0,1,0,1,0,0,0,0},
                   {0,1,0,1,0,0,1,1,1,1,1,0,0,0,0},
                   {0,1,0,1,0,0,0,0,0,0,0,1,1,1,0},
                   {0,0,0,1,0,1,1,1,0,1,1,1,0,1,0},
                   {0,0,0,1,1,1,0,1,0,1,0,1,0,1,0},
                   {0,1,0,0,0,0,0,1,1,1,0,1,0,1,1},
                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}};



    system("cls");system("color B");
    printMaze(maze);

    rat(maze,0,0);

    gotoxy(0,N+6);
    return 0;
}
