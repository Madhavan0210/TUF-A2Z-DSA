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
    node* intersection(node* head1,node* head2)
    {
        node* t1=head1;
        node* t2=head2;
        while(t1!=t2)
        {
            t1=t1->next;
            t2=t2->next;
            if(t1==t2) return t1;
            if(t1==NULL) t1=head2;
            if(t2==NULL) t2=head1;
        }
        return t1;
    }
};
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  linkedlist list;
  node* head1;
  node* head2;
  head1=list.insertathead(1);
  head1=list.insertathead(2);
  head1=list.insertathead(3);
  head1=list.insertathead(4);
  head1=list.insertathead(5);
  head1=head1->next->next;
  list.print();
  cout<<endl;
  linkedlist list1;
  head2=list1.insertathead(0);
  head2->next=head1;
  list1.print();
  cout<<endl;
  node* val=list.intersection(head1,head2);
  cout<<val->data;
  return 0;
}