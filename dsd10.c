#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define maxsize 300
//fp
void read_cgpa(int N,float cgpa[maxsize]);
void display_cgpa(int N,float cgpa[maxsize]);
int count_registered(int N,float cgpa[maxsize]);
float minimum(int N,float cgpa[maxsize]);
float maximum(int N,float cgpa[maxsize]);
int main() {
    int N;
    float cgpa[maxsize];
    float min,max;
    int count;

    scanf("%d",&N);
    if(N>0 && N<=300)
    { read_cgpa( N,cgpa);
    display_cgpa( N,cgpa);
    count=count_registered(N,cgpa);
    min=minimum(N,cgpa);
    max=maximum(N,cgpa);
     printf("\nRegistered = %d",count);
     printf("\nMinimum cgpa = %0.1f\n",min);
     printf("Maximum cgpa = %0.1f",max);

    }
    else
        printf("invalid");
    return 0;
}
void read_cgpa(int N,float cgpa[maxsize])
{
    int i;
    for(i=0;i<N;i++)
        scanf("%f",&cgpa[i]);
}
void display_cgpa(int N,float cgpa[maxsize])
{
    int i;
    for(i=0;i<N;i++)
        printf("%0.1f ",cgpa[i]);
}
int count_registered(int N,float cgpa[maxsize])
{
    int i;
    int count=0;
   float avg=8.00;
    for(i=0;i<N;i++)
    {
        if(cgpa[i]>=avg)

        {count=count+1;
        }
    }
    return count;
}
float minimum(int N,float cgpa[maxsize])
{
    int i;
    float min=10.00;
    for(i=0;i<N;i++)
    { if(cgpa[i]<min)
    {  min=cgpa[i];
    }
    }
    return min;
}
float maximum(int N,float cgpa[maxsize])
{
    int i;
    float max=0;
        for(i=0;i<N;i++)
        {
            if(cgpa[i]>max)
                max=cgpa[i];
        }
    return max;
}


