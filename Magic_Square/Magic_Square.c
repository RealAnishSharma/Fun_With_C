#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    //case 1:
    int n,i,j,u,v,f;
    scanf("%d",&n);printf("\n");
    int a[n][n];
    if(n%2!=0)
    {
        f=n/2;
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        a[i-1][j-1]=n*((i+j-1+f)%n)+((i+2*j-2)%n)+1;
    }
    /////////////////////////////////////////////
    if(n%2==0)
    {
        //case 2:
        if(n%4!=0)
        {
            int p=n/2;f=p/2;
            for(i=1;i<=p;i++)
            for(j=1;j<=p;j++)
            a[i-1][j-1]=p*((i+j-1+f)%p)+((i+2*j-2)%p)+1;

            for(i=1;i<=p;i++)
            for(j=1;j<=p;j++)
            a[i-1+p][j-1+p]=a[i-1][j-1]+p*p;

            for(i=1;i<=p;i++)
            for(j=1;j<=p;j++)
            a[i-1][j-1+p]=a[i-1][j-1]+2*p*p;

            for(i=1;i<=p;i++)
            for(j=1;j<=p;j++)
            a[i-1+p][j-1]=a[i-1][j-1]+3*p*p;

            u=(n-2)/4;
            v=u-1;

            for(i=0;i<p;i++)
            for(j=0;j<u;j++)
            {
                f=a[i+p][j];
                a[i+p][j]=a[i][j];
                a[i][j]=f;
            }

            for(i=0;i<p;i++)
            for(j=n-1;j>n-1-v;j--)
            {
                f=a[i+p][j];
                a[i+p][j]=a[i][j];
                a[i][j]=f;
            }

            int x=p/2;
            f=a[x+p][u];
            a[x+p][u]=a[x][u];
            a[x][u]=f;

            f=a[x+p][0];
            a[x+p][0]=a[x][0];
            a[x][0]=f;
        }
        ///////////////////////////////////////////////
        //case 3:
        if(n%4==0)
        {
            int p=n/4,count=1,b[(n*n)/2],k=0;
            for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if((i<p&&j<p)||(i<p&&j>=n-p)||(i>=n-p&&j<p)||(i>=n-p&&j>=n-p)||((i>=p&&i<n-p)&&(j>=p&&j<n-p)))
                {a[i][j]=count;}
                else
                {a[i][j]=-1;b[k]=count;k++;}
                count++;
            }

            for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(a[i][j]==-1) {a[i][j]=b[k-1];k--;}
            }
        }
      //////////////////////////////////////////////////////
    }

    //display//
    for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d\t",a[i][j]);
    }printf("\n");}
    return 0;
}
