#include<bits\stdc++.h>
using namespace std;
class Node{
 public:
 int key;
 int value;
 int cnt;
 Node* prev;
 Node* next;
 Node(int key1,int val)
 {
    key=key1;
    value=val;
    cnt=1;
 }
};
class List{
    public:
    int size;
    Node* head;
    Node* tail;
    List()
    {
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addfront(Node* node)
    {
        Node* temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
        size++;
    }
    void removenode(Node* delnode)
    {
        Node* delprev=delnode->prev;
        Node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        size--;
    }
};
class LFUCache{
 public:
 map<int,Node*>keynode;
 map<int,List*> freqListMap;
 int maxsizecache;
 int minfreq;
 int cursize;
 LFUCache(int capacity)
 {
    maxsizecache=capacity;
    minfreq=0;
    cursize=0;
 }
 void updatefreqlistmap(Node* node)
 {
    keynode.erase(node->key);
    freqListMap[node->cnt]->removenode(node);
    if(node->cnt==minfreq && freqListMap[node->cnt]->size==0)
    {
        minfreq++;
    }
    List* nextHigherFreqList=new List();
    if(freqListMap.find(node->cnt+1)!=freqListMap.end())
    {
        nextHigherFreqList=freqListMap[node->cnt+1];
    }
 }
 int get(int key){
    if(keynode.find(key)!=keynode.end())
    {
        Node* node=keynode[key];
        int val=node->value;
        updatefreqlistmap(node);
        return val;
    }
    return -1;
 }
 void put(int key,int val)
 {
    if(maxsizecache==0) return ;
    if(keynode.find(key)!=keynode.end()){
        Node* node=keynode[key];
        node->value=val;
        updatefreqlistmap(node);
    }
    else
    {
        if(cursize==maxsizecache){
            List* list=freqListMap[minfreq];
            keynode.erase(list->tail->prev->key);
            freqListMap[minfreq]->removenode(list->tail->prev);
            cursize--;
        }
    cursize++;
    minfreq=1;
    List* listfreq=new List();
    if(freqListMap.find(minfreq)!=freqListMap.end())
    {
        listfreq=freqListMap[minfreq];
    }
    Node* node=new Node(key,val);
    listfreq->addfront(node);
    keynode[key]=node;
    freqListMap[minfreq]=listfreq;
}
 }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    return 0;
}