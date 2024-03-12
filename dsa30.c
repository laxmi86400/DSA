#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[20];
    char gen[20];
    int age;
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
        scanf("%s%s%d",newnode->name,newnode->gen,&newnode->age);
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
            printf("%s %s %d\n",cur->name,cur->gen,cur->age);
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
 struct node* insert_position(struct node *head,struct node *newnode)
{
    struct node *cur=head,*prev=NULL;
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
     while(cur!=NULL)
     {
        if(cur->age==newnode->age)
        {
            break;
        }
        cur=cur->right_link;
    }
      prev=cur->left_link;
      prev->right_link=newnode;
     newnode->right_link=cur;
     newnode->left_link=prev;
     cur->left_link=newnode;
    }
    return head;
}
int search(struct node *head,struct node *newnode)
{
    struct node *cur=head;
    int count=0;
    if(head==NULL)
    {
        printf("List empty\n");
    }
    else
    {
        while(cur!=NULL)
        {
            count++;
            if(cur->age==newnode->age)
            {
                break;
            }
            cur=cur->right_link;
        }
    }
    return count;
}
int main() {
struct node *head=NULL,*newnode=NULL;
    int n,f,count;
    scanf("%d",&n);
    scanf("%d",&f);
    if(n>=5)
    {
        for(int i=0;i<n;i++)
        {
          head=insert_end(head);
        }
         newnode=createnode();
        head=insert_position(head,newnode);
        display_forward(head);
        count=search(head,newnode);
        printf("%d",count);
    }
    else
    {
        printf("Soldiers cannot go on a war\n");
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
