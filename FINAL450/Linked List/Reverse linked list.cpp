// https://www.geeksforgeeks.org/reverse-a-linked-list/

// Reverse a linked list

//Initial Template for C
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    
}*start;

void insert();
void display(struct Node *head);

 // } Driver Code Ends
//User function Template for C

//ITERATIVE APPROACH

struct Node* reverseList(struct Node *head)
    {
        struct Node* nh=NULL;
       struct Node* curr=NULL;
       struct Node* prev=NULL;
       struct Node* next=NULL;
       curr=head;
       while(curr)
       {
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
           
       }
       
        return prev;
    }

//RECURSIVE APPROACH

// struct Node* reverseList(struct Node *head)
//     {
//         struct Node* nh=NULL;
//        struct Node* curr=NULL;
//        struct Node* prev=NULL;
//        struct Node* next=NULL;
//        curr=head;
//        while(curr)
//        {
//            next=curr->next;
//            curr->next=prev;
//            prev=curr;
//            curr=next;
           
//        }
       
//         return prev;
//     }


// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      start=NULL;
      insert();
      start = reverseList(start);
      display(start);
      printf("\n");
    }
    return 0;

}


 void insert()
 {
     int n,value,i;
     scanf("%d",&n);
     struct Node *temp;
     for(i=0;i<n;i++)
     {
         scanf("%d",&value);
         if(i==0)
         {
              start=(struct Node *) malloc( sizeof(struct Node) );
              start->data=value;
              start->next=NULL;
              temp=start;
              continue;
         }
         else
         {
             temp->next= (struct Node *) malloc( sizeof(struct Node) );
             temp=temp->next;
             temp->data=value;
             temp->next=NULL;
         }
     }
 }
 
 void display(struct Node *head)
{
   while(head!=NULL)
  {
   printf("%d ",head->data);
    head=head->next;
  }
}
