#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define maxsize 20
void read(int N,float avg[maxsize]);
void display(int N,float avg[maxsize]);
void hightolow(int N,float avg[maxsize]);

int main() {
    int N;
    float avg[maxsize];

    scanf("%d",&N);
    if(N>=11)
    {
        read(N,avg);

        hightolow(N,avg);
        printf("Top 11 batting average players:\n");
        display(11,avg);
    }
    else
        printf("Number of players should be atleast 11.\n");

    return 0;

}
void read(int N,float avg[maxsize])
{
    int i;
    for(i=0;i<N;i++)
        scanf("%f",&avg[i]);
}
void display(int N,float avg[maxsize])
{
    int i;
    for(i=0;i<N;i++)
        printf("%0.2f ",avg[i]);
}

void hightolow(int N,float avg[maxsize])
{
    int i,j;
    float temp;
    for(i=0;i<N-1;i++)
    {
        for(j=0;j<N-i-1;j++)
        {
            if(avg[j]<avg[j+1])
            {
                temp=avg[j];
                avg[j]=avg[j+1];
                avg[j+1]=temp;

            }
        }
    }


}
