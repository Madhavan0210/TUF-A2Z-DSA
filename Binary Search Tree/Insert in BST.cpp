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
  Node(int data1)
  {
    data=data1;
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
  Node* insertIntoBST(Node* root, int val) {
        if(root==NULL) return new Node(val);
        Node* head=root;
        while(true)
        {
        if(root->data<=val)
        {
            if(root->right!=NULL) root=root->right;
            else
            {
                root->right=new Node(val);
                break;
            }
        }
        else
        {
            if(root->left!=NULL) root=root->left;
            else{
                root->left=new Node(val);
                break;
            }
        }
        }
        return head;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Solution s;
    Node* temp=s.create();
    cout<<s.insertIntoBST(temp,7);
    return 0;
}