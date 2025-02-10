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
    int helper(node* temp)
    {
        if(temp==NULL) return 1;
        int carry=helper(temp->next);
        temp->data+=carry;
        if(temp->data<10) return 0;
        temp->data=0;
        return 1;
    }
    node* add1toll(node* head1)
    {
     int carry=helper(head1);
     if(carry==1)
     {
        node* newnode=new node(1);
        newnode->next=head1;
         head1=newnode;
     }
     return head1;
    }
};
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  linkedlist list;
  node* head1;
  node* head2;
  head1=list.insertathead(9);
  head1=list.insertathead(9);
  head1=list.insertathead(9);
  head1=list.insertathead(9);
  list.print();
  cout<<endl;
  head1=list.add1toll(head1);
  cout<<head1->data;
  cout<<endl;
   while(head1!=NULL)
   {
    cout<<head1->data<<" ";
    head1=head1->next;
   }
  return 0;
}