#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[20];
    char hn[20];
    int sn;
    int no;
    struct node *link;
};
struct node* createcsll()
{
    struct node *newnode=NULL;
        newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    printf("Memory is not allocated\n");
    else
    {
        scanf("%s%s%d%d",newnode->name,newnode->hn,&newnode->sn,&newnode->no);
        newnode->link=newnode;
    }
    return newnode;
}
struct node* insertendcsll(struct node *head,struct node *newnode)
{


    struct node *cur=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        cur=head;
        while(cur->link!=head)
        {
            cur=cur->link;
        }
        cur->link=newnode;
        newnode->link=head;

    }
    return head;
}
void displaycsll(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
        printf("Empty.\n");
    else
    {
        cur=head;
        do
        {
            printf("%s %s %d %d\n",cur->name,cur->hn,cur->sn,cur->no);
            cur=cur->link;
        }
        while(cur!=head);
    }
}
void display(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
        printf("Empty.\n");
    else
    {
        cur=head;
        do
        { if(cur->no > 5)
         printf("%s %s %d %d\n",cur->name,cur->hn,cur->sn,cur->no);

            cur=cur->link;
        }
        while(cur!=head);
    }
}
struct node* delete_letter(struct node *head)
{
    struct node *cur=NULL,*pre=NULL,*temp=NULL;
    int status=0;
    if(head==NULL)
        return NULL;
    else if(head->link==head&&head->no==0)
    { status=1;
      printf("%s %s %d %d\n",head->name,head->hn,head->sn,head->no);
     free(head);
     head=NULL;

    }
    else if(head->no==0)
    {
        cur=head;
        while(cur->link!=head)
        {
            cur=cur->link;
        }
        status=1;
        printf("%s %s %d %d\n",cur->name,cur->hn,cur->sn,cur->no);
        temp=head;
        cur->link=head->link;
        head=head->link;
        free(temp);

    }
    else
    {
        pre=head;
        cur=head->link;
        do
        {  if(cur->no==0)
        {
            status=1;
            break;
        }
            pre=cur;
            cur=cur->link;

        }while(cur!=head);
        if(cur==head)
            status=0;
        else
        {
            pre->link=cur->link;
            printf("%s %s %d %d\n",cur->name,cur->hn,cur->sn,cur->no);
            free(cur);

        }
    }
    if(status==0)
        printf("No house to delete.\n");
   return head;
}
int main() {

    int n;
    struct node *head=NULL;
    scanf("%d",&n);
    if(n>1)
    { struct node *newnode=NULL;
        for(int i=0;i<n;i++)
        {
            newnode=createcsll();
            head=insertendcsll(head,newnode);
        }
        printf("Houses postman visits:\n");
        displaycsll(head);

        printf("\nDeleted house:\n");
        head=delete_letter(head);

        printf("\nUpdated houses list:\n");
     displaycsll(head);

        printf("\nHouses with more than 5 letters:\n");
        display(head);

    }
    else
        printf("Invalid input\n");

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

