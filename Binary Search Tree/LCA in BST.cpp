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
  Node* LCA(Node* root,int p,int q)
  {
    if(root==NULL) return NULL;
    int curr=root->data;
    if(curr>p && curr>q) return LCA(root->left,p,q);
    if(curr<p && curr<q) return LCA(root->right,p,q);
    return root;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Solution s;
    Node* temp=s.create();
    Node* ans=s.LCA(temp,1,3);
    cout<<ans->data;
    return 0;
}