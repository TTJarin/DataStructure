#include<bits/stdc++.h>
using namespace std;
typedef struct node *Node;

struct node
{
    int data;
    Node next;
};
Node head=NULL;
void insertAtEnding(int value)
{
    Node newNode=(Node)malloc(sizeof(Node));
    if(head==NULL)
    {
        newNode->data=value;
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
        newNode->data=value;
        currentNode->next=newNode;
        newNode->next=NULL;

    }

}
void insertAtBegining(int value)
{
    Node newNode=(Node)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
}
void insertAtGivenPosition(Node currentNode,int value)
{
    Node newNode=(Node)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=currentNode->next;
    currentNode->next=newNode;
}
void deleteAtBegining()
{
    head=head->next;
}
void deleteAtEnd()
{
    Node currentNode=head;
    while(currentNode->next->next!=NULL)
    {
        currentNode=currentNode->next;
    }
    currentNode->next=NULL;
}
void deleteNode(int value)
{
    Node temp=head,prev;
    if(temp!=NULL&&temp->data==value)
    {
        head=temp->next;
        return;
    }
    while(temp!=NULL&&temp->data!=value)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        return;
    }
    prev->next=temp->next;

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
    for(int i=0;i<5;i++)
    {
        int value;
        cin>>value;
        insertAtEnding(value);
    }
    cout<<"linked list :"<<" ";
    display(head);
    cout<<endl;
    insertAtBegining(0);
    cout<<"After inserting element 0 at the begining of the linkedList"<<endl;
    display(head);
    cout<<endl;
    insertAtGivenPosition(head,1);
    insertAtGivenPosition(head->next,2);
    cout<<"After inserting 1 and 2 in position  2 and 3 :"<<endl;
    display(head);
    cout<<endl;
    deleteAtBegining();
    cout<<"After deleting 1st index :"<<endl;
    display(head);
    cout<<endl;
    deleteAtEnd();
    cout<<"After deleting last index :"<<endl;
    display(head);
    cout<<endl;
    deleteNode(1);
    cout<<"After deleting element 1 :"<<endl;
    display(head);
    cout<<endl;
    return 0;
}