#include<bits\stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node()
    {
        data=0;
        next=NULL;
    }
    node(int data1)
    {
        data=data1;
        next=NULL;
    }
};
class linkedlist{
    node *head,*temp;
    public:
    linkedlist()
    {
        head=NULL;
    }
    node* insertathead(int data1)
    {
        node* newnode=new node(data1);
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        return head;
    }
    void print()
    {
      node* temp=head;
      while(temp!=NULL)
      {
        cout<<temp->data<<" ";
        temp=temp->next;
      }
    }
    node* reversell(node* head)
    {
        node* prevnode=NULL;
        node* nextnode=NULL;
        node* temp=head;
        while(temp!=NULL)
        {
            nextnode=temp->next;
            temp->next=prevnode;
            prevnode=temp;
            temp=nextnode;
        }
        head=prevnode;
        return head;
    }
    node* findnode(node* temp,int k)
    {
        k-=1;
        while(temp!=NULL &&k>0)
        {
            temp=temp->next;
            k--;
        }
        return temp;
    }
    void reversepairs(int k)
    {
        node* temp=head;
        node* kthnode=NULL;
        node* prevnode=NULL;
        node* nextnode=NULL;
        node* head1;
        while(temp!=NULL)
        {
         kthnode=findnode(temp,k);
         if(kthnode==NULL)
         {
            if(prevnode) prevnode->next=temp;
            break;
         }
         nextnode=kthnode->next;
         kthnode->next=NULL;
         head1=reversell(temp);
         if(temp==head) head=head1;
         else{
            prevnode->next=head1;
         }
         prevnode=temp;
         temp=nextnode;
        }

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
  list.insertathead(4);
  list.insertathead(5);
  list.insertathead(6);
  list.insertathead(7);
  list.insertathead(8);
  list.insertathead(9);
  list.insertathead(10);
  list.print();
  cout<<endl;
  int k=3;
  list.reversepairs(k);
  list.print();
  return 0;
}