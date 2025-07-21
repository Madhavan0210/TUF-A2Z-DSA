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
     Node* TempNode=root;
     while(!st.empty())
     {
        if(TempNode!=NULL)
        {
            st.push(TempNode);
            TempNode=TempNode->left;
        }
        else
        {
            if(st.empty()) break;
            TempNode=st.top();
            st.pop();
            ans.push_back(TempNode->data);
            TempNode=TempNode->right;
        }
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
    vector<int> vec=s.preorder(temp);
    for(auto it:vec) cout<<it<<" ";
    return 0;
}