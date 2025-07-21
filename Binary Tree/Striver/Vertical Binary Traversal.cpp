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
  vector<vector<int>> ZigZagTraversal(Node* root)
  {
    map<int,map<int,multiset<int>>>mpp;
    queue<pair<Node*,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        Node* temp=p.first;
        int x=p.second.first;
        int y=p.second.second;
        mpp[x][y].insert(temp->data);
        if(temp->left!=NULL) q.push({temp->left,{x-1,y+1}});
        if(temp->right!=NULL) q.push({temp->right,{x+1,y+1}});
    }
    vector<vector<int>>ans;
    for(auto a:mpp)
    {
        vector<int>temp;
        for(auto b:a.second)
        temp.insert(temp.end(),b.second.begin(),b.second.end());
        ans.push_back(temp);
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
    vector<vector<int>>vec=s.ZigZagTraversal(temp);
    for(auto it:vec)
    {
      for(auto it1:it)
      {
        cout<<it1<<" ";
      }
      cout<<endl;
    } 
    return 0;
}