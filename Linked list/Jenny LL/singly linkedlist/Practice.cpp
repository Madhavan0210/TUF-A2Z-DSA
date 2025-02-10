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
    void Insertathead(int data1)
    {
        node* newnode=new node(data1);
        if(head==NULL)
        {
            head=temp=newnode;
            return;
        }
        temp->next=newnode;
        temp=newnode;
    }
    void Insertatbeginning(int data1)
    {
        node *newnode=new node(data1);
        newnode->next=head;
        head=newnode;
    }
    void Insertatend(int data1)
    {
        node *newnode=new node(data1);
        newnode->next=0;
        node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;

    }
    void print()
    {
        node *temp=head;
        if(head==NULL)
        {
            cout<<"Empty";
            return ;
        }
        while(temp!=0)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void insertatgivenpos(int data1,int k)
    {
        node *newnode=new node(data1);
      node *temp=head;
      int i=1;
      while(i<k)
      {
        temp=temp->next;
        i++;
      }
      newnode->next=temp->next;
      temp->next=newnode;
    }
    void deleteatbegin()
    {
        node *temp=head;
        head=head->next;
       // cout<<temp->data<<endl;
        free(temp);
    }
    void deletefromend()
    {
        node *temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=0;
    }
    void deletegivpos(int pos)
    {
        node *temp=head;
        node *prev;
        int i=1;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        prev=temp->next;
        temp->next=prev->next;
        free(prev);
    }
    void reverse()
    {
        node *prevnode,*nextnode,*temp;

        nextnode=temp=head;
        while(temp!=0)
        {
            nextnode=temp->next;
            temp->next=prevnode;
            prevnode=temp;
            temp=nextnode;
        }
        head=prevnode;
    }
    void removed(int val)
    {
        node* nextnode=NULL;
        node* temp=head;
        node* prev=NULL;
        while(temp!=NULL)
        {
            if(temp->data==val)
            {
                 
                if(temp==head) 
                {
                    head=head->next;
                }
                nextnode=temp->next;
                if(prev!=NULL)  prev->next=nextnode;

                delete(temp);
                temp=nextnode;
            }
            else 
            {
                prev=temp;
                temp=temp->next;
            }
        }
    }

};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  linkedlist list;
  list.Insertathead(1);
  list.Insertathead(2);
  list.Insertathead(6);
  list.Insertathead(3);
  list.Insertathead(4);
  list.Insertathead(5);
  list.Insertathead(6);
    list.print();
    cout<<endl;
    int key=6;
   list.removed(key);
    list.print();
  return 0;
}