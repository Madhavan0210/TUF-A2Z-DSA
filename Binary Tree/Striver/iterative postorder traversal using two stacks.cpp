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
  vector<int>postorder(Node* root)
  {
     stack<Node*>st1;
     stack<Node*>st2;
     st1.push(root);
     vector<int>ans;
     while(!st1.empty())
     {
        Node* temp=st1.top();
        st1.pop();
        st2.push(temp);
        if(temp->left!=NULL) st1.push(temp->left);
        if(temp->right!=NULL) st1.push(temp->right);
     }
     while(!st2.empty())
     {
        Node* temp=st2.top();
        st2.pop();
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
    vector<int> vec=s.postorder(temp);
    for(auto it:vec) cout<<it<<" ";
    return 0;
}