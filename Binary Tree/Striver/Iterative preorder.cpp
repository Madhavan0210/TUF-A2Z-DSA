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
  vector<int>preorder(Node* root)
  {
    stack<Node*>st;
    vector<int>ans;
    st.push(root);
    while(!st.empty())
    {
        Node* temp=st.top();
        st.pop();
        if(temp->right!=NULL) st.push(temp->right);
        if(temp->left!=NULL) st.push(temp->left);
        ans.push_back(temp->data);
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
    vector<int> ans=s.preorder(temp);
    for(auto it:ans) cout<<it<<" ";
    return 0;
}