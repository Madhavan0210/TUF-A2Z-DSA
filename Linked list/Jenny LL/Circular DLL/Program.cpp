#include<bits\stdc++.h>
using namespace std;
class node{
   public:
   int data;
   node *prev;
   node *next;
   node(int data1)
   {
    data=data1;
    prev=0;
    next=0;
   }
   node()
   {
    data=0;
    prev=0;
    next=0;
   }
};
class linkedlist {
    
    node *head,*tail;
    public:
    linkedlist()
    {
        head=NULL;
    }
    void insertathead(int data1)
    {
        node *newnode=new node(data1);
        if(head==NULL)
        {
            head=tail=newnode;
            head->next=head;
            head->prev=head;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }
    }
    void print()
    {
        node *temp=head;
        if(head==NULL)
        {
            cout<<"Empty";
            return ;
        }
        while(temp!=tail)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data;
    }
    
    void reverse()
    {
        node* temp=head,*newnode;
        while(temp!=tail)
        {
            newnode=temp->next;
            temp->next=temp->prev;
            temp->prev=newnode;
            temp=newnode;
        }
        newnode=temp->next;
            temp->next=temp->prev;
            temp->prev=newnode;
            temp=newnode;
        temp=head;
        head=tail;
        tail=temp;
    }
    
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    linkedlist list;
    list.insertathead(5);
    list.insertathead(3);
    list.insertathead(1);
    list.insertathead(7);
    list.insertathead(10);
    list.print();
    cout<<endl;
    list.reverse();
    list.print();
    return 0;
}