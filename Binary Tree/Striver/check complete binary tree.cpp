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
  int height(Node* root)
  {
    if(root==NULL) return 0;

    int l=height(root->left);
    if(l==-1) return -1;
    int r=height(root->right);
    if(r==-1) return -1;
    if(abs(l-r)>1) return -1;
    return 1+max(l,r);
  }
  bool checkBT(Node* root)
  {
    return height(root)!=-1;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Solution s;
    Node* temp=s.create();
    cout<<s.checkBT(temp);
    return 0;
}