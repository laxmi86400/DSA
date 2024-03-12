#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//function prototype
void sum_even_odd(int n);

int main() {
    int n;
    scanf("%d",&n);
    if(n>0)
    { //function call
    sum_even_odd(n);
    }
    else
        printf("Invalid input");
     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

//function definition
void sum_even_odd(int n)
{ int i=1, osum=0, esum=0, num;
 while(i<=n)
 {
     scanf("%d",&num);
     if(num%2 == 0)
         esum += num;
     else
         osum += num;
       i++;
 }
 printf("Sum of even numbers=%d\n",esum);
 printf("Sum of odd numbers=%d\n",osum);





}

