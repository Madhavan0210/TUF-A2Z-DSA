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
node* reversebyrecurr(node *head)
{
    if(head==NULL || head->next==NULL) return head;
    node *newhead=reversebyrecurr(head->next);
    node *front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
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
    node* head1=list.print();
    cout<<endl;
    node *temp=list.reversebyrecurr(head1);
    while(temp!=0)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}