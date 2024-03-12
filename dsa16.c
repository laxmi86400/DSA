#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max 100


void read(int arr[max],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}
void odd(int arr[max],int n)
{
    int xor=0;
    int i;
    for(i=0;i<n;i++)
    {
        xor=xor^arr[i];
    }
    printf("%d ",xor);
}
int main()
{
    int arr[max];
    int n;
    scanf("%d",&n);
    if(n>0)
    {
        read(arr,n);
        odd(arr,n);

    }
    else
        printf("Invalid\n");
}


