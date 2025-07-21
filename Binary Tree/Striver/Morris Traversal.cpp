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
  vector<int>getInorder(Node* root)
  {
    vector<int>inorder;
    Node* curr=root;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            inorder.push_back(curr->data);
            curr=curr->right;
        }
        else
        {
            Node* prev=curr->left;
            while(prev->right && prev->right!=curr)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                inorder.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    return inorder;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Solution s;
    Node* temp=s.create();
     vector<int>ans=s.getInorder(temp);
     for(auto it:ans) cout<<it<<" ";
    return 0;
}