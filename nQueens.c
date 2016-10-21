//A program to print n queen's solutions
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>

int n,flg=0,count=1;

void printSolution(int array[n][n])
{
    printf("-----------------------------\n");
    printf("Solution number::%d\n",count);
    int b=count%10;
    system("COLOR b");

    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(array[i][j]==1)
            printf("%c ",'Q');
            else
            printf("%c ",'*');
        printf("\n");
    }
    printf("-------------------------\n");
}


bool iscorrect(int arr[n][n],int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
        if(arr[row][i])return false;

    for(i=row,j=col;i>=0&&j>=0;i--,j--)
        if(arr[i][j]) return false;

    for(i=row,j=col;j>=0&&i<n;i++,j--)
        if(arr[i][j]) return false;

    return true;
}



bool checkQ(int arr[n][n],int col,int k)
{
    if(col>=n)
    {
     return true;
    }

    int i;
    for(i=0;i<n;i++)
    {
        if(iscorrect(arr,i,col))
        {
            arr[i][col]=1;
            if(checkQ(arr,col+1,k))
             {
                 if(k==1) return true;
                printSolution(arr);
                count++;flg=1;

             }
            arr[i][col]=0;
        }
    }

    return false;
}





int main()
{
    int k;
    printf("Enter the size of n queen board:\n");
    scanf("%d",&n);


    printf("You want \nOne solution(Enter 1)\nMany Solutions\(Enter 2)\n");
    scanf("%d",&k);


    int i,j,arr[n][n];

    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    arr[i][j]=0;


    if(checkQ(arr,0,k)==false&&flg==0)
    printf("\nNo solution Possible");
    if(k==1)
        printSolution(arr);
    printf("\n\t<-<-Thats all buddy->->\t");
    getch();
    return 0;

}
