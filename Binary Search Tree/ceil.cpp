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
  int findCeil(Node* root,int value)
  {
    int ceil=-1;
    while(root)
    {
        if(root->data==value)
        {
           ceil=root->data;
           root=root->right;
        }
        if(value<root->data) root=root->right;
        else
        {
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Solution s;
    Node* temp=s.create();
    cout<<s.findCeil(temp,7);
    return 0;
}