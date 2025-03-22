#include<bits\stdc++.h>
using namespace std;
class Node
{
  public:
   int data;
   Node* next;
  Node()
  {
    data=0;
    next=NULL;
  }  
  Node(int data1)
  {
    data=data1;
    next=NULL;
  }
};
class Linkedlist
{
 Node *head,*rear,*temp;
 public:
  Linkedlist()
  {
    head=NULL;
    rear=NULL;
  }
  void enqueue(int data1)
  {
    Node* newnode=new Node(data1);
    if(head==NULL)
    {
        head=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
  }
  void dequeue()
  {
    if(head==NULL) cout<<"Empty";
    else if(head->next==NULL) 
    {
        cout<<"Empty"<<endl;
        head=NULL;
    }
    else
    {
        temp=head;
        head=head->next;
        delete(temp);
    }
  }
  void display()
  {
    if(head==NULL) cout<<"Empty";
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  Linkedlist l1;
  l1.enqueue(1);
  l1.enqueue(2);
  l1.enqueue(3);
  l1.dequeue();
  l1.display();
  return 0;
}