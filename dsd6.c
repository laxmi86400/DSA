#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define num 1000
void read(int number[num],int n);
void display(int number[num],int n);
int minimum(int number[num],int n);

int main() {
    int n;
    int number[num];
    int min;
    scanf("%d",&n);
    if(n>0)
    {
        read(number,n);
        display(number,n);
       min=minimum(number,n);
        printf("\nLowest number in array is %d.",min);
    }
    else
        printf("Array should not be less than 0.");



    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

void read(int number[num],int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&number[i]);

}
void display(int number[num],int n)
{
   int i;
    for(i=0;i<n;i++)
        printf("%d ",number[i]);

}
int minimum(int number[num],int n)
{  int i;
 int min=99999999;
 for(i=0;i<n;i++)
 {
    if(number[i]<min)
     min=number[i];

 }

 return min;
}

