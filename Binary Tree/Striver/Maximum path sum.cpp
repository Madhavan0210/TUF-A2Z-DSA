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
  int helper(Node* root,int &cnt)
  {
    if(root==NULL) return 0;
    int l=max(0,helper(root->left,cnt));
    int r=(0,helper(root->right,cnt));
    cnt=max(cnt,l+r+root->data);
    return max(l,r)+root->data;
  }
  int MaximumPathSum(Node* root)
  {
    int cnt=0;
    helper(root,cnt);
    return cnt;
  }
  
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Solution s;
    Node* temp=s.create();
    cout<<s.MaximumPathSum(temp);
    return 0;
}