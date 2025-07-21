#include<bits\stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node()
  {
    data=0;
    left=NULL;
    right=NULL;
  }
};
class Solution{
  public:
  Node* create()
  {
    int a;
    cin>>a;
    Node* newnode=new Node();
    if(a==-1) return 0;
    newnode->data=a;
    newnode->left=create();
    newnode->right=create();
    return newnode;
  }
  int MaxWidth(Node* root)
  {
    if(!root) return 0;
    int ans=0;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        int size=q.size();
        int mmin=q.front().second;
        int first;
        int last;
        for(int i=0;i<q.size();i++)
        {
            int id=q.front().second-mmin;
            Node* temp=q.front().first;
            q.pop();
            if(i==0) first=id;
            if(i==size-1) last=id;
            if(temp->left) q.push({temp->left,id*2+1});
            if(temp->right) q.push({temp->right,id*2+2});
        }
        ans=max(ans,last-first+1);
    }
    return ans;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Solution s;
    Node* temp=s.create(); 
    cout<<s.MaxWidth(temp);
    return 0;
}