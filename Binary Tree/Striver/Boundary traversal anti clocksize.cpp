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
   bool isLeaf(Node* temp)
   {
    if(temp->left==NULL && temp->right==NULL) return true;
    return false;
   }
  void LeftBoundary(Node* root,vector<int>&ans)
  {
    Node* curr=root->left;
    while(curr)
    {
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
    
  }
   void RightBoundary(Node* root,vector<int>&ans)
  {
    Node* curr=root->right;
    stack<int>st;//or vector any you can use
    while(curr)
    {
        if(!isLeaf(curr)) st.push(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    while(!st.empty())
    {
        int temp=st.top();
        st.pop();
        ans.push_back(temp);
    }
   
  }
  void addLeaves(Node* root,vector<int>&ans)
  {
    Node* curr=root;
    if(isLeaf(curr))
    {
        ans.push_back(curr->data);
        return;
    }
    if(curr->left) addLeaves(curr->left,ans);
    if(curr->right) addLeaves(curr->right,ans);
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Solution s;
    Node* temp=s.create();
    vector<int>ans;
    ans.push_back(temp->data);
    s.LeftBoundary(temp,ans);
    s.addLeaves(temp,ans);
    s.RightBoundary(temp,ans);
    for(auto it:ans) cout<<it<<" ";
    return 0;
}