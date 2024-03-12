#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define maxsize 100
//function prototype
void read(int marks[maxsize],int N);
void display(int marks[maxsize],int N);
int main() {
    int N,marks[maxsize];
    scanf("%d",&N);
    if(N>0)
    { read(marks,N);
    display(marks,N);}
    else
        printf("Elements should be more than 0.");



    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
void read(int marks[maxsize],int N)

{int i;
 for(i=0;i<N;i++)
     scanf("%d ",&marks[i]);

}
void display(int marks[maxsize],int N)
{
   int i;
    for(i=0;i<N;i++)
    printf("%d ",marks[i]);

}
