#include<bits/stdc++.h>
using namespace std;
typedef struct node *Node;

struct node
{
    int data;
    Node next;
};
Node head=NULL;
void insertQueue(int item)
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
        while(currentNode->next!=NULL)
        {
            currentNode=currentNode->next;
        }
        newNode->data=item;
        currentNode->next=newNode;
        newNode->next=NULL;
    }
}
void deleteQueue()
{
    head=head->next;
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
        insertQueue(x);
    }
    cout<<"Our Queue is : ";
    display(head);
    cout<<endl;
    deleteQueue();
    cout<<"After deleting our new Queue is : ";
    display(head);
    cout<<endl;
    deleteQueue();
    cout<<"After deleting our new Queue is : ";
    display(head);
    cout<<endl;

    return 0;
}