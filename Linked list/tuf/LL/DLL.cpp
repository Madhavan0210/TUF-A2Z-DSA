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
    next=NULL;
    prev=NULL;
  }
};
class linkedlist{
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
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    void deleteatbegin()
    {
        if(head==NULL) cout<<"Empty";
        else 
        {
            node *temp=head;
            head=temp->next;
            head->prev=0;
            free(temp);
        }
    }
    void deleteattail()
    {
        if(head==NULL) cout<<"empty";
        else
        {
        node *temp=tail;
        tail=temp->prev;
        tail->next=0;
        free(temp);
        }
    }
    void position(int k)
    {
        if(head==NULL) cout<<"empty";
        else
        {
            node *temp=head,*nextnode;
            int cnt=1;
            while(temp!=0)
            {
                nextnode=temp->next;
                if(cnt==k-1)
                {
                   nextnode->next->prev=temp;
                   temp->next=nextnode->next;
                   free(nextnode);
                }
                cnt++;
                temp=temp->next;
            }
        }
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
    void display()
    {
        node *temp=head;
        while(temp!=0)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int arr[5]={1,2,3,4,5};
    linkedlist list;
    for(int i=0;i<5;i++)
    {
      list.insertathead(arr[i]);
    }
    //list.deleteatbegin();
    //list.deleteattail();
    list.position(3);
    list.reverse();
    list.display();
    return 0;
}