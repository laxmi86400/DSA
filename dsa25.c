#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[20];
    char place[20];
    int d;
    struct node *link;
};
struct node* createnode()
{
    struct node *newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("Memory is not allocated\n");
    else
    {
        scanf("%s%s%d",newnode->name,newnode->place,&newnode->d);
        newnode->link=NULL;
    }
    return newnode;
}
struct node* insertend(struct node *head)
{
    struct node *newnode=NULL,*cur=NULL;
    newnode=createnode();
    if(head==NULL)
        head=newnode;
    else{
        cur=head;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;


    }
    return head;
}
void display(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
      printf("Empty\n");
    else
    {
        cur=head;

      while(cur!=NULL)
        {
            printf("%s %s %d\n",cur->name,cur->place,cur->d);
            cur=cur->link;
        }
    }
}
struct node* minimum(struct node *head)
{
    struct node *cur=NULL,*low=NULL;
    int min=99999;
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        cur=head;

       while(cur!=NULL)
        {
            if(cur->d<min)
            {
                min=cur->d;
                low=cur;
            }
            cur=cur->link;
        }
        printf("Person nearest is:\n");
        printf("%s %s %d\n",low->name,low->place,low->d);
    }
    return head;
}


struct node* deletemax(struct node *head)
{
 struct node *cur=NULL,*pre=NULL,*pre_high=NULL,*high=NULL;
    int max=-1;
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            if(cur->d>max)
            {
                max=cur->d;
                pre_high=pre;
                high=cur;

            }
            pre=cur;
            cur=cur->link;
        }
        if(head==high)
        {
            head=head->link;
            free(high);
        }
        else
        {
            pre_high->link=high->link;
            free(high);
        }
    }
    return head;
}


int main() {
    int n;
    scanf("%d",&n);
    struct node *head=NULL;
    if(n>0)
    {
        for(int i=0;i<n;i++)
            head=insertend(head);
       head=minimum(head);
        printf("\n");
        printf("Updated trip list is:\n");
        head=deletemax(head);
        //printf("Updated trip list is:\n");
        display(head);
    }
    else
        printf("Invalid input\n");

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
