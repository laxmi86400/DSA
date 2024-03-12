#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define r 100
#define c 100
void read(int arr[r][c],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}

void display(int arr[r][c],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }

        printf("\n");
    }
    printf("\n");


}


int rowsum(int arr[r][c],int sum[100],int m,int n)
{
 int i,j;
 for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum[i]=sum[i]+arr[i][j];
        }

    }
    for(i=0;i<m;i++)

    {

        printf("Player %d: %d\n",i+1,sum[i]);

    }


    return sum[i];

}

void maximum(int arr[r][c],int sum[100],int m)
{
    int i;
    int max=0;
    int index;
    for(i=0;i<m;i++)
    {
        if(max<sum[i])
        {   max=sum[i];
    index=i+1;
        }
    }
    printf("\n");
    printf("Player %d has highest total runs scored of %d",index,max);
}


int main()
{


    int arr[r][c];
    int sum[100]={0};
    int m,n;
    scanf("%d%d",&m,&n);
    if(m>5 && n==3)
    {
        read(arr,m,n);
        display(arr,m,n);
    rowsum(arr,sum,m,n);
    maximum(arr,sum,m);

    }
    else
    { printf("Invalid players or game formats");}

    return 0;
}

