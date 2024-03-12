#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define maxsize 100
void read(int N,int votes[maxsize]);

int maximum(int N,int votes[maxsize]);
int main() {
    int N;
    int votes[maxsize];
    int max;
    scanf("%d",&N);
    if(N>0 && N<=100)
    { //fc
       read(N,votes);
        max=maximum(N,votes);
    printf("Winner among contestants with maximum votes = %d",max);
    }

    else
        printf("Cannnot determine winner.");

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

void read(int N,int votes[maxsize])

{
    int i;
    for(i=0;i<N;i++)
        scanf("%d",&votes[i]);

}


int maximum(int N,int votes[maxsize])
{
    int i;
    int max=0;

    for(i=0;i<N;i++)
    {
        if(votes[i]>max)
            max=votes[i];
    }
    return max;


}


