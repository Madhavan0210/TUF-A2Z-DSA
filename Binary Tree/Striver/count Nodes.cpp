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
   int findheightLeft(Node* root)
    {
        int height=0;
        while(root)
        {
            height++;
            root=root->left;
        }
        return height;
    }
     int findheightRight(Node* root)
    {
        int height=0;
        while(root)
        {
            height++;
            root=root->right;
        }
        return height;
    }

    int countNodes(Node* root) {
        int lh=findheightLeft(root);
        int rh=findheightRight(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Solution s;
    Node* temp=s.create();
    cout<<s.countNodes(temp);
    return 0;
}