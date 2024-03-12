#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define maxsize 100
void read(int arr[maxsize],int n);
void reverse(int arr[maxsize],int n);
int main() {
    int arr[maxsize];
    int n;
    scanf("%d",&n);
    if(n>0)
    {
        read(arr,n);
        reverse(arr,n);
    }
    else
        printf("Absent students should be more than 0.\n");

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
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
void reverse(int arr[maxsize],int n)
{
    int i;
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",arr[i]);
    }
}
