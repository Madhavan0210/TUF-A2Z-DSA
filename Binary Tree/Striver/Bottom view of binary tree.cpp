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
  vector<int> ZigZagTraversal(Node* root)
  {
    queue<pair<Node*,int>>q;
    map<int,int>mpp;
    vector<int>ans;
    q.push({root,0});
    while(!q.empty())
    {
      auto p=q.front();
      Node* temp=p.first;
      int axis=p.second;
      q.pop();
      mpp[axis]=temp->data;
      if(temp->left) q.push({temp->left,axis-1});
      if(temp->right) q.push({temp->right,axis+1});
    }
     for(auto it:mpp)
     {
        ans.push_back(it.second);
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
    vector<int>vec=s.ZigZagTraversal(temp);
    for(auto it:vec)
    {
      cout<<it<<" ";
    } 
    return 0;
}