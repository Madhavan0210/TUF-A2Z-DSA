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
    node* findnode(node* head,int k)
    {
        cout<<k<<" "<<endl;
        int cnt=1;
        node* temp=head;
        while(temp!=NULL)
        {
            if(cnt==k) return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    void rotate(int k)
    {
        node* tail=NULL;
        node* temp=head;
        int len=1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            len++;
        }
        tail=temp;
        tail->next=head;
        if(k%len==0) return;
        k=k%len;
        node* kthnode=findnode(head,k);
        head=kthnode->next;
        kthnode->next=NULL;
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
    list.print();
    cout<<endl;
    int k=4;
    list.rotate(k);
    list.print();
    return 0;
}