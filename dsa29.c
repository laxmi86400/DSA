#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int hn;
    float amount;
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
        scanf("%d%f",&newnode->hn,&newnode->amount);
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
            printf("%d %0.2f\n",cur->hn,cur->amount);
            cur=cur->right_link;
        }
    }
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
float totalamount(struct node *head)

{
    struct node *cur=NULL;
    int total=0.00;
    if(head==NULL)
        printf("No nodes\n");
    else
    {
        cur=head;
        total=total+cur->amount;
        while(cur->right_link!=NULL)
        {

            cur=cur->right_link;
        }
        total=total+cur->amount;
    }
    return total;
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

int main() {
    int n;
    scanf("%d",&n);

    struct node *head=NULL;
    if(n>=5)
    {
        for(int i=0;i<n;i++)
        { head=insert_end(head);
        }
        float sum=0.00,total=0.00;
       total=totalamount(head);
        sum=total;
        head=delete_end(head);
        head=delete_front(head);
        display_forward(head);
        printf("Total loot = %0.2f",sum);
    }
    else
    {
        printf("Kaalia cannot loot houses\n");
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
