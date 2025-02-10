#include<bits\stdc++.h>
using namespace std;
class node {
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
class linkedlist{
    node *head,*temp,*tail;
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
      }
      tail->next=newnode;
      newnode->prev=tail;
      tail=newnode;

    }
    void insertatbeginning(int data1)
    {
      node *temp,*newnode;
      newnode=new node(data1);
      head->prev=newnode;
      newnode->next=head;
      head=newnode;

    }
    void insertatend(int data1)
    {
        node *temp=head,*newnode;
        newnode=new node(data1);

        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
        tail=newnode;
    }
    void deleteatfirst()
    {
        node *temp=head;
        head=head->next;
        head->prev=0;
        free(temp);
    }
    void deletaatend()
    {
        node *temp=head;
        while(temp->next->next)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=0;
 
    }
    void deleteatpos(int pos)
    {
        node *temp=head,*nextnode;
        int i=1;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        nextnode=temp->next;
        temp->next=nextnode->next;
        nextnode->next->prev=temp; 
    }
     void print1()
    {
        node *temp=head,*temp1;
        if(head==NULL)
        {
            cout<<"Empty";
            return ;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
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
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
   void reverse()
   {
    node *temp,*nextnode;
    temp=head;
    while(temp!=0)
    {
        nextnode=temp->next;
        temp->next=temp->prev;
        temp->prev=nextnode;
        temp=nextnode;
    }
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
    list.insertathead(1);
    list.insertathead(2);
    list.insertathead(3);
    list.insertatbeginning(0);
    list.insertatend(4);
    list.deleteatfirst();
    list.deleteatpos(2);
    //list.deletaatend();
    list.reverse();
    list.print1();
return 0;
}