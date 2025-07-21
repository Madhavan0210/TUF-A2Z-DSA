#include<bits\stdc++.h>
using namespace std;
class TreeNode{
  public:
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode()
  {
    data=0;
    left=NULL;
    right=NULL;
  }
  TreeNode(int val)
  {
   data=val;
   left=NULL;
   right=NULL;
  }
};
class Solution{
  public:
  TreeNode* create()
  {
    int a;
    cin>>a;
    TreeNode* newnode=new TreeNode();
    if(a==-1) return 0;
    newnode->data=a;
    newnode->left=create();
    newnode->right=create();
    return newnode;
  }
   TreeNode* LCA(TreeNode* root,TreeNode* p,TreeNode* q)
   {
    if(root==NULL || root->data==p->data || root->data==q->data) return root;
    TreeNode* l=LCA(root->left,p,q);
    TreeNode* r=LCA(root->right,p,q);
    if(l==NULL) return r;
    else if(r==NULL) return l;
    else return root;
   }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Solution s;
    TreeNode* root=s.create();
    TreeNode* p=new TreeNode(4);
    TreeNode* q=new TreeNode(7);
    TreeNode* ancestor=s.LCA(root,p,q); 
    if(ancestor==NULL) cout<<"HI";
    cout<<ancestor->data<<endl;
    return 0;
}