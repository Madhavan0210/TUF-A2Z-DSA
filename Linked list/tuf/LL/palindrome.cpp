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
     node* reverse(node *head)
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
        return head;
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
    bool palindrome()
    {
        node* slow=head;
        node* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        node *newhead=reverse(slow->next);
        node* first=head;
        node* second=newhead;
        while(second!=NULL)
        {
            if(first->data!=second->data) 
            {
                reverse(newhead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverse(newhead);
        return true;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    linkedlist list;
    int n;
    cin>>n;
    int val;
    for(int i=0;i<n;i++)
    { 
      cin>>val;
      list.Insertathead(val);
    }
    list.print();
    cout<<endl;
    cout<<list.palindrome();
    return 0;
}