#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define maxsize 100
void read(int arr[maxsize],int n );
void display(int arr[maxsize],int n);
void repeated(int arr[maxsize],int n);

int main(){
    int n;
    int arr[maxsize];
    scanf("%d",&n);
    if(n>0)
    {
        read(arr,n);

        repeated(arr,n);


    }
    else
        printf("Invalid");
    return 0;
}
void read(int arr[maxsize],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}
void display(int arr[maxsize],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void repeated(int arr[maxsize],int n)
{
    int pos=-1,i,j,num;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {   if(arr[i]==arr[j])
        { num=arr[j];
            pos=j;
            break;
        }
        }

    if(pos!=-1)
        break;
    }
    if(pos!=-1)
        printf("%d\n",num);
    else
        printf("No repeating element\n");



}

