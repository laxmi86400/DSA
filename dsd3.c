#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define number 1000
void read(int num[number],int n);
void display(int num[number],int n);
int maximum(int num[number],int n);
int main() {
    int n;
    int num[number];
    int max;
    scanf("%d ",&n);
    if(n>0)
    { read(num,n);
    display(num,n);
       max=maximum(num,n);}
    else
    {printf("Array cannot be less than 0.");}





    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
void read(int num[number],int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d ",&num[i]);

}
void display(int num[number],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",num[i]);

}



int maximum(int num[number],int n)
{
    int i,max=0;
    for(i=0;i<n;i++)
    { if(num[i]>max)
        { max=num[i];
        }
    }
     printf("\nHighest number in array is %d.",max);
    return max;

}

