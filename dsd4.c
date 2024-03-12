#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define maxsize 100
void read(int num[maxsize],int n);
void display(int num[maxsize],int n);
int search(int num[maxsize],int n,int key);

int main() {
    int n,num[maxsize],key,status;
    scanf("%d",&n);
    if(n>0)
    {
        read(num,n);
        scanf("%d",&key);
        display(num,n);
        status=search(num,n,key);
        if(status==1)
            printf("\nSearch successfull. %d found in list.\n",key);
        else
            printf("\nSearch unsuccessfull. %d not found in list.\n",key);

    }
    else
        printf("array should be greater than 0.\n");


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
void read(int num[maxsize],int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);

}
void display(int num[maxsize],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",num[i]);
}
int search(int num[maxsize],int n,int key)

{
   int i,status=0;
    for(i=0;i<n;i++)
    {
       if(key == num[i])
       {
           status=1;
           break;
       }

    }
   return status;
}


