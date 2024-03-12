#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define row 10
#define col 10
void read(int num[row][col],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
}

void display(int num[row][col],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",num[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int num[row][col];
    int m,n;
    scanf("%d %d",&m,&n);
    if(m>0 && n>0)
    {//fc
    read(num,m,n);
    display(num,m,n);
    }
    else
        printf("Rows and columns should be more than 0.\n");


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

