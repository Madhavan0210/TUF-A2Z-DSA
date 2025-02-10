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
    
};
node* addinteger(node* head,node* head1)
    {
        node *t1=head;
        node *t2=head1;
        node *ans=new node(-1);
        node* dummy=ans;
        node *newnode;
        int sum=0,carry=0;
        while(t1!=NULL || t2!=NULL)
        {
            sum=carry;
            if(t1)
            {
                sum=sum+t1->data;
                t1=t1->next;
            }
            if(t2)
            {
                sum=sum+t2->data;
                t2=t2->next;
            }
           newnode=new node(sum%10);
           carry=sum/10;
           dummy->next=newnode;
           dummy=dummy->next;
        }
        if(carry)
        {
            newnode=new node(carry);
            dummy->next=newnode;
        }
        return ans->next;
    }
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    linkedlist list;
    list.Insertathead(3);
    list.Insertathead(5);
    node* head=list.print();
     cout<<endl;
    linkedlist list1;
    list1.Insertathead(4);
    list1.Insertathead(5);
    list1.Insertathead(9);
    list1.Insertathead(9);
    node* head1=list1.print();
    cout<<endl;
    node *temp=addinteger(head,head1);
    while(temp!=0)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}