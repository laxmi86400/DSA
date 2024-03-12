#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    char name[20],mm[20];
    int h_no,dd,yy;
    float amount;
    struct node *link;
};

struct node* create_node()
{
    struct node *newnode=NULL;
        newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    printf("No memory allocated\n");
    else
    {
        scanf("%s%d%d%s%d%f",newnode->name,&newnode->h_no,&newnode->dd,newnode->mm,&newnode->yy,&newnode->amount);
        newnode->link=newnode;
    }
    return newnode;
}

struct node* insert_end_csll(struct node *head)
{
    struct node *newnode=create_node();
    struct node *cur=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        cur=head;
        while(cur->link!=head)
            cur=cur->link;
        cur->link=newnode;
        newnode->link=head;

    }
    return head;
}

void display_list(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
    {
        printf("List empty\n");
    }
    else
    {
        cur=head;
        do
        {
            printf("%s %d %d %s %d %0.2f\n",cur->name,cur->h_no,cur->dd,cur->mm,cur->yy,cur->amount);
            cur=cur->link;
        }
        while(cur!=head);
    }
}

struct node* delete_low(struct node *head)
{
    struct node*prev=NULL,*cur=NULL,*temp=NULL;
    int status =0;
    if(head==NULL)
        printf("List empty\n");

    else if(head->link==head && head->amount<500)
    {//check single node with amount<500
        status=1;
         printf("%s %d %d %s %d %0.2f\n",head->name,head->h_no,head->dd,head->mm,head->yy,head->amount);
        free(head);
        head=NULL;
    }
    else if(head->amount<500)//first node out of multiple nodes
    {
        cur=head;
        while(cur->link!=head)
            cur=cur->link;
           printf("%s %d %d %s %d %0.2f\n",head->name,head->h_no,head->dd,head->mm,head->yy,head->amount);
        status=1;
        temp=head;
        cur->link=head->link;
        head=head->link;
        free(temp);
   }
    else
    {
        prev=head;
        cur=head->link;
        do
        {
            if(cur->amount<500)
            {
                status=1;
                break;
            }
            prev=cur;
            cur=cur->link;
        }
        while(cur!=head);

    if(cur==head)
        status=0;
    else
    {
        prev->link=cur->link;
         printf("%s %d %d %s %d %0.2f\n",cur->name,cur->h_no,cur->dd,cur->mm,cur->yy,cur->amount);
        free(cur);

    }
   }
    if(status==0)
        printf("No node to delete\n");
    return head;
}

int count_node(struct node *head)
{
    int count=0;
    struct node*cur=NULL;
    if(head==NULL)
        return count;
    else
    {
        cur=head;
        do
        {
            count++;
            cur=cur->link;
        }
        while(cur!=head);
    }
    return count;
}


float total_amount(struct node *head)
{
    float total=0;
    struct node *cur=NULL;
    if(head==NULL)
        printf("List empty\n");
    else
    {
        cur=head;
        do
        {
            total+=cur->amount;
            cur=cur->link;
        }
        while(cur!=head);
    }
    return total;
}


int main()
{
    struct node *head=NULL;
    int n;
    scanf("%d",&n);

  if(n>0)
  {


    for(int i=0;i<n;i++)
        head=insert_end_csll(head);
    printf("Total amount: Rs.%0.2f\n",total_amount(head));
    printf("\nDeleted order:\n");
    head=delete_low(head);
    printf("\nFinal orders list:\n");
    display_list(head);
  }

    else
        printf("Invalid input\n");

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

