#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char data;
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
        scanf(" %c",&newnode->data);
        newnode->right_link=NULL;
        newnode->left_link=NULL;
    }
    return newnode;
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
            printf("%c ",cur->data);
            cur=cur->right_link;
        }
    }
}

struct node* insert_front(struct node *head)
{
    struct node *newnode=createnode();
    if(head==NULL)
        head=newnode;
    else
    {
        newnode->right_link=head;
        head->left_link=newnode;
        head=newnode;
    }
    return head;
}
struct node* delete_front(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
        printf("list empty\n");
    else
    {
        cur=head;
        head=head->right_link;
        head->left_link=NULL;
        free(cur);
    }
    return head;
}
struct node* delete_end(struct node *head)
{
    struct node *cur=NULL,*prev=NULL;
    if(head==NULL)
        printf("list empty\n");
    else
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
    return head;

}
int main() {
struct node *head=NULL;
    int n,k;
    scanf("%d",&n);
    if(n>0)
    {
        for(int i=0;i<n;i++)
        {
          head=insert_front(head);
        }
        printf("DLL before deletion:\n");
        display_forward(head);
        printf("\n");
        printf("\n");
        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            head=delete_front(head);
            head=delete_end(head);
        }
        printf("DLL after deletion:\n");
        display_forward(head);
    }
    else
        printf("N should be positive.\n");

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

