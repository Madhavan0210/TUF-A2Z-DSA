#include<bits\stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node* next;
    node(){
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
        else 
        {
          tail->next=newnode;
          tail=newnode;
          tail->next=head;
        }
    }
    void print()
    {
        node *temp=tail->next;
        if(head==NULL)
        {
            cout<<"Empty";
            return ;
        }
        while(temp->next!=tail->next)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data;
    }
    void deleteatbegin()
    {
        node *temp=tail->next;
        tail->next=temp->next;
        free(temp);
    }
    void insertatbeginning(int data1)
    {
     node *newnode=new node(data1);
     newnode->next=head;
     head=newnode;
     tail->next=head;
    }
    void insertatposition(int data1,int pos)
    {
        node* temp=head;
        node* newnode=new node(7);
        int i=1;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    linkedlist list;
    list.insertathead(5);
    list.insertathead(88);
    list.insertathead(1);
    list.insertatbeginning(0);
    list.insertatposition(7,2);
    list.deleteatbegin();
    list.print();
    return 0;
}