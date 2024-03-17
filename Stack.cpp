#include<bits/stdc++.h>
using namespace std;
typedef struct node *Node;

struct node
{
    int data;
    Node next;
};
Node head=NULL;
void push(int item)
{
   Node newNode=(Node)malloc(sizeof(Node));
   if(head==NULL)
   {
     newNode->data=item;
     newNode->next=head;
     head=newNode;
   }
   else
   {
     Node currentNode=head;
     while(currentNode->next)
     {
        currentNode=currentNode->next;
     }
     newNode->data=item;
     currentNode->next=newNode;
     newNode->next=NULL;
   } 
}
void pop()
{
    Node currentNode=head;
    while(currentNode->next->next!=NULL)
    {
        currentNode=currentNode->next;
    }
    currentNode->next=NULL;
}
void display(Node head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        push(x);
    }
    cout<<"After push elements , new stack is : ";
    display(head);
    cout<<endl;
    pop();
    cout<<"After pop , new stack is : ";
    display(head);
    cout<<endl;


    return 0;
}