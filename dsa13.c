#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 200
void read_array(int n,float color[MAX_SIZE]);
void add_array(int n,float c1[MAX_SIZE],float c2[MAX_SIZE],float sum[MAX_SIZE]);
int main() {
  int n;
  float c1[MAX_SIZE],c2[MAX_SIZE],sum[MAX_SIZE];
    scanf("%d",&n);
    if(n>0)
    {
       read_array(n,c1);
        read_array(n,c2);
        add_array(n,c1,c2,sum);
    }
    else
        printf("Rows should be more than 0.");
    return 0;
}
void read_array(int n,float color[MAX_SIZE])
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%f",&color[i]);
    }
}
void add_array(int n,float c1[MAX_SIZE],float c2[MAX_SIZE],float sum[MAX_SIZE])
{
    int i;
    for(i=0;i<n;i++)
    {
        sum[i]=c1[i]+c2[i];
        printf("%0.1f ",sum[i]);
    }
}
