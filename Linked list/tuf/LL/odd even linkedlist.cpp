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
     void reverse()
    {
         node *prevnode=NULL,*nextnode,*curr;

        nextnode=curr=head;
        while(curr!=0)
        {
            nextnode=curr->next;
            curr->next=prevnode;
            prevnode=curr;
            curr=nextnode;
        }
        head=prevnode;
    }
    
     node* print()
    {
        node *ans=head;
        if(head==NULL)
        {
            cout<<"Empty";
            return NULL;
        }
        while(ans!=NULL)
        {
            cout<<ans->data<<" ";
            ans=ans->next;
        }
        return head;
    }
    node* oddevenseparate(node* head)
{
   node* odd=head;
   node* even=odd->next;
   node* evenhead=odd->next;
   while(even && even->next!=NULL)
   {
    odd->next=odd->next->next;
    even->next=even->next->next;
    odd=odd->next;
    even=even->next;
   }
   odd->next=evenhead;
   return head;
}
    
};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    linkedlist list1;
    list1.Insertathead(1);
    list1.Insertathead(2);
    list1.Insertathead(5);
    list1.Insertathead(6);
    list1.Insertathead(11);
    list1.Insertathead(12);
    list1.Insertathead(15);
    node* head1=list1.print();
    cout<<endl;
    cout<<"After separation:"<<endl;
    node* temp=list1.oddevenseparate(head1);
    while(temp!=0)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}