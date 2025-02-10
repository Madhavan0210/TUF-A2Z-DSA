#include<bits\stdc++.h>
using namespace std;
  class node{
    public:
        int data;
        node * next;
    };
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int val=0;
    node  *head,*temp,*newnode;
    head=0;
    for(int i=0;i<3;i++)
    {
    newnode=new node();
    cin>>newnode->data;
    newnode->next=0;
    if(head==0) head=temp=newnode;
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
    }
    temp=head;
    while(temp!=0) 
    {
        cout<<temp->data<<endl;
        cout<<temp->next<<endl;
        temp=temp->next;
    }
    return 0;
}