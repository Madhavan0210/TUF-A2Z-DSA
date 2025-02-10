#include<bits\stdc++.h>
using namespace std;
class Node
{
  public:
  int data;
  Node* prev;
  Node* next;
  Node(int data1)
   {
    data=data1;
    prev=NULL;
    next=NULL;
   }
   Node()
   {
    data=0;
    prev=NULL;
    next=NULL;
   }
};
class Linkedlist
{
    Node *head,*temp;
    public:
    Linkedlist()
    {
        head=NULL;
    }
    void insertathead(int data1)
    {
        Node* newnode=new Node(data1);
        if(head==NULL)
        {
            head=temp=newnode;
            head->prev=NULL;
            head->next=NULL;
        }
        else
        {
           temp->next=newnode;
           newnode->prev=temp;
           newnode->next=NULL;
           temp=newnode; 
        }
    }
    void print()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    Node* Deleteallkey(int key)
    {
        Node* temp=head;
        Node* nextnode=NULL;
        Node* prevnode=NULL;
        while(temp!=NULL)
        {
            if(temp->data==key)
            {
                if(temp==head) 
                {
                    head=head->next;
                    head->prev=NULL;
                }
                nextnode=temp->next;
                prevnode=temp->prev;
                if(prevnode!=NULL) prevnode->next=nextnode;
                if(nextnode!=NULL) nextnode->prev=prevnode;
                delete(temp);
                temp=nextnode;
            }
            else
            temp=temp->next;
        }
        return head;
    }

};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
Linkedlist list;
list.insertathead(2);
list.insertathead(2);
list.insertathead(3);
list.insertathead(2);
list.insertathead(5);
list.print();
cout<<endl;
int key=2;
list.Deleteallkey(key);
list.print();
return 0;
}