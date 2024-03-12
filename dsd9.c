#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define maxsize 100
void read(int N,int marks[maxsize]);
void display(int N,int marks[maxsize]);
float per(int N,int marks[maxsize]);
int maximum(int N,int marks[maxsize]);

int main() {
    int N;
    int marks[maxsize];
    float percentage;
    int max;
    scanf("%d",&N);
    if(N>=6 && N<=10)
    {
    read(N,marks);
     display(N,marks);
    percentage=per(N,marks);
    max=maximum(N,marks);
    printf("\nPercentage: %0.2f\n",percentage);
    printf("Highest marks: %d\n",max);
    }
    else
        printf("Subjects cannot be less than 6 and more than 10.\n");
    return 0;
}
void read(int N,int marks[maxsize])
{
     int i;
    for(i=0;i<N;i++)
        scanf("%d ",&marks[i]);
}
void display(int N,int marks[maxsize])
{
    int i;
    for(i=0;i<N;i++)
        printf("%d ",marks[i]);
}
float per(int N,int marks[maxsize])
{
    int i;
    int sum=0;

    float percentage;
    for(i=0;i<N;i++)
    {
        sum = sum + marks[i];
    }
    percentage=((float)sum/(N*100))*100;
    return percentage;

}
int maximum(int N,int marks[maxsize])
{
    int i;
    int max=0;
    for(i=0;i<N;i++)
    {if(marks[i]>max)
    {
        max=marks[i];
    }
    }
    return max;
}



