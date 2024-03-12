#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<ctype.h>
#define SIZE 100


struct stack
{
    char exp[SIZE];
    int top;
};

void push(struct stack *sptr, char ch)
{
    if(sptr->top == SIZE-1)
        printf("Stack overflow\n");
    else
    {
        sptr->top++;
        sptr->exp[sptr->top] = ch;
    }
}

char pop(struct stack *sptr)
{
    int ch;
    if(sptr->top==-1)
        return '\0';
    else
    {
        ch = sptr->exp[sptr->top];
        sptr->top--;
        return ch;
    }
}

int peek(struct stack *sptr)
{

    char ch;
    if(sptr->top==-1)
        return '\0';
    else
    {
        ch=sptr->exp[sptr->top];
        return ch;

    }

}


int check(struct stack *sptr,char exp[SIZE])
{
    int i=0;
    char ch;
    while(exp[i]!='\0')
    {
        if(exp[i]=='('|| exp[i]=='{'|| exp[i]=='[')
        {
            push(sptr,exp[i]);
        }
        else if(exp[i]==')')
        {
            if(sptr->top==-1)
                return 0;
            else
            {
                ch=pop(sptr);
                if(ch !='(')
                    return 0;
            }
        }
        else if(exp[i]=='}')
        {
            if(sptr->top==-1)
                return 0;
            else
            {
                ch=pop(sptr);
                if(ch!='{')
                    return 0;
            }
        }
      else if(exp[i]==']')
        {
            if(sptr->top==-1)
                return 0;
            else
            {
                ch=pop(sptr);
                if(ch!='[')
                    return 0;
            }
        }
        i++;
   }//end of while loop
        if(sptr->top==-1)
            return 1;//valid expression
        else
            return 0;

}


int main()
{
    struct stack s;
      struct stack *sptr;
    sptr=&s;
    sptr->top=-1;
    char exp[SIZE];

    scanf("%s",exp);
    int valid=check(sptr,exp);
    if(valid==1)
        printf("Valid snippet\n");
    else
        printf("Invalid snippet\n");

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}


