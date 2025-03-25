#include<bits\stdc++.h>
using namespace std;
class node
{
  public:
  int data;
  node* next;
  public:
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
class stackk
{
 node* top;
 public:
 stackk()
 {
    top=NULL;
 }
 void pushh(int data1)
 {
   node* newnode=new node(data1);
   newnode->next=top;
   top=newnode;
 }
 void popp()
 {
    node* temp=top;
    top=top->next;
    free(temp);
 }
 void display()
 {
   node* temp=top;
   while(temp!=NULL)
   {
    cout<<temp->data<<" ";
    temp=temp->next;
   }
   cout<<endl;
 }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    stackk s;
    s.pushh(2);
    s.pushh(3);
    s.pushh(5);
    s.display();
    s.popp();
    s.display();
    return 0;
}