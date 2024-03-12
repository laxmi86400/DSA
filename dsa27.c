#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right_link,*left_link;
};
struct node* createnode()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("Memory not allocated\n");
    else
    {
        scanf("%d",&newnode->data);
        newnode->right_link=NULL;
        newnode->left_link=NULL;
    }
    return newnode;
}
struct node* insert_end(struct node *head)
{
    struct node *cur=NULL;
    struct node *newnode=createnode();
    if(head==NULL)
        head=newnode;
    else
    {
        cur=head;
        while(cur->right_link!=NULL)
        {
            cur=cur->right_link;
        }
        cur->right_link=newnode;
        newnode->left_link=cur;
    }
    return head;
}

void display_forward(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
        printf("DLL Empty\n");
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%d ",cur->data);
            cur=cur->right_link;
        }
    }
}
int countnodes(struct node *head)
{
    struct node *cur=NULL;
    int count=0;
    if(head==NULL)
        printf("No nodes\n");
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            count++;
            cur=cur->right_link;
        }
    }
    return count;
}
struct node* insert_position(struct node *head,int pos)
{
    struct node *cur=NULL,*prev=NULL;
    struct node *newnode=createnode();
    int count=countnodes(head);
    if(head==NULL)
        head=newnode;
    else if(pos<=1)
    {
        newnode->right_link=head;
        head->left_link=newnode;
        head=newnode;
    }
    else if(pos>count)
    {
        cur=head;
        while(cur->right_link!=NULL)
        {
            cur=cur->right_link;
        }
        cur->right_link=newnode;
        newnode->left_link=cur;
    }
    else if(pos>1 && pos<=count)
    {
        cur=head;
        for(int i=1;i<pos;i++)
        {
            cur=cur->right_link;
        }
        prev=cur->left_link;


        prev->right_link=newnode;
        newnode->left_link=prev;
        newnode->right_link=cur;
        cur->left_link=newnode;
    }
    return head;

}
struct node* delete_position(struct node *head,int pos)
{
    struct node *cur=NULL,*prev=NULL,*next=NULL;
    int count=countnodes(head);
    if(head==NULL)
        printf("List empty\n");
    else if(head->right_link==NULL && pos==1)
    {
        free(head);
        head=NULL;
    }
    else if(pos==1)
    {
        cur=head;
        head=head->right_link;
        head->left_link=NULL;
        free(cur);
    }
    else if(pos==count)
    {
        cur=head;
        while(cur->right_link!=NULL)
        {
            cur=cur->right_link;
        }
        prev=cur->left_link;
        prev->right_link=NULL;
        free(cur);
    }
    else if(pos>1 && pos<count)
    {
        cur=head;
        for(int i=1;i<pos;i++)
        {
            cur=cur->right_link;
        }
        prev=cur->left_link;
        next=cur->right_link;
        prev->right_link=next;
        next->left_link=prev;
        free(cur);
    }
    return head;
}
int main() {
struct node *head=NULL;
    int n,p,e;
    scanf("%d",&n);
    if(n>0)
    {
        for(int i=0;i<n;i++)
            head=insert_end(head);
        scanf("%d",&p);
        head=insert_position(head,p);
        display_forward(head);
        printf("\n\n");
        scanf("%d",&e);
        head=delete_position(head,e);
        display_forward(head);



    }
    else
        printf("Invalid position\n");

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

