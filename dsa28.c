#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[20];
    int year;
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
        scanf(" %s%d",newnode->name,&newnode->year);
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
            printf("%s %d\n",cur->name,cur->year);
            cur=cur->right_link;
        }
    }
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
void display(struct node *head)
{  int kyear;
 scanf("%d",&kyear);
    struct node *cur=NULL;
 int s=0;
    if(head==NULL)
        printf("DLL Empty\n");
    else
    {
        cur=head;
        while(cur!=NULL)
        {  if(cur->year==kyear)
        {   s=1;
            printf("%s %d\n",cur->name,cur->year);
        }
            cur=cur->right_link;
        }
    }
 if(s==0)
     printf("No web series in %d\n",kyear);
}


int countnodes(struct node *head)
{
    struct node *cur=NULL;
    int kyear;
    scanf("%d",&kyear);
    int count=0;
    if(head==NULL)
        printf("No nodes\n");
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            if(cur->year==kyear)
           {
                count++;

            }
            cur=cur->right_link;
        }
    }
    return count;
}


int main() {
    int n;
    int count;
    scanf("%d",&n);
    struct node *head=NULL;
    if(n>1)
    {
        for(int i=0;i<n;i++)
            head=insert_end(head);
        display_forward(head);
        printf("\n");
        count=countnodes(head);
      display(head);
        printf("\n");
        printf("%d",count);

    }
    else
        printf("Invalid input.\n");

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

