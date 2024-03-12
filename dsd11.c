#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define maxsize 100
//function protoytype
void read(int N, int candles[maxsize]);
void display(int N,int candles[maxsize]);
int maximum(int N,int candles[maxsize]);
int candles_blown(int N,int candles[maxsize],int max);
int main() {
    int N;
    int candles[maxsize];
    int max,blown;
    scanf("%d",&N);
    if(N>0)
    {
        read(N,candles);
        display(N,candles);
        max=maximum(N,candles);
       blown=candles_blown(N,candles,max);
        printf("\nTallest Candle = %d\n",max);
        printf("Tallest Candles blown = %d",blown);
    }
   else

   {
       printf("Invalid input.");
   }

    return 0;
}
void read(int N,int candles[maxsize])
{
    int i;
    for(i=0;i<N;i++)
        scanf("%d",&candles[i]);
}
void display(int N,int candles[maxsize])
{
    int i;
    for(i=0;i<N;i++)
        printf("%d ",candles[i]);
}
int maximum(int N,int candles[maxsize])
{
    int i,max=0;
    for(i=0;i<N;i++)
    {
        if(candles[i]>max)
            max=candles[i];

    }
    return max;
}
int candles_blown(int N,int candles[maxsize],int max)
{
    int i;

    int blown=0;
    for(i=0;i<N;i++)
    {
        if(candles[i]==max)
            blown=blown+1;
    }
    return blown;
}

