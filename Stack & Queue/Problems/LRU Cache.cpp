#include<bits\stdc++.h>
using namespace std;
class Node
{
    public:
       int key;
       int val;
       Node* prev;
       Node* next;
     Node()
     {
        key=-1;
        val=-1;
     }  
     Node(int key1,int value)
     {
        key=key1;
        val=value;
     }
};
class LRUCache
{
  private:
   map<int,Node*>mpp;
   Node* head;
   Node* tail;
   int capacity;
  public:
  LRUCache(int capacity1)
  {
    capacity=capacity1;
    mpp.clear();
    head=new Node(-1,-1);
    tail=new Node(-1,-1);
    head->next=tail;
    tail->prev=head;
  } 
   void deletenode(Node* temp)
   {
    Node* prev=temp->prev;
    Node* next=temp->next;
    prev->next=next;
    next->prev=prev;
   }
   void insertafterhead(Node* temp)
   {
    Node* currafterhead=head->next;
    temp->next=currafterhead;
    temp->prev=head;
    head->next=temp;
    currafterhead->prev=temp;
   }
  int get(int key)
  {
    if(mpp.find(key)==mpp.end()) return -1;
    Node* temp=mpp[key];
    deletenode(temp);
    insertafterhead(temp);
    return temp->val;
  }
  void put(int key,int value)
  {
    if(mpp.find(key)!=mpp.end())
    {
        Node* temp=mpp[key];
        temp->val=value;
        deletenode(temp);
        insertafterhead(temp);
    }
    else
    {
        if(mpp.size()==capacity)
        {
            Node* temp=tail->prev;
            mpp.erase(key);
            deletenode(temp);
        }
        Node* temp=new Node(key,value);
        insertafterhead(temp);
        mpp[key]=temp;
        
    }
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int capacity1=4;
    LRUCache l(capacity1);
    l.put(2,6);
    l.put(4,7);
    l.put(8,11);
    l.put(7,10);
    cout<<l.get(2)<<endl;
    cout<<l.get(8)<<endl;
    l.put(5,6);
    cout<<l.get(7)<<endl;
    l.put(5,7);
   return 0;
}