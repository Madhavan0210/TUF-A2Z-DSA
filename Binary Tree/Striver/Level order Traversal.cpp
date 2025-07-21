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
  vector<vector<int>> levelorder(Node* root)
  {
    queue<Node*>q;
    vector<vector<int>>ans;
    q.push(root);
    while(!q.empty())
    {
        vector<int>temp;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node* Tnode=q.front();
            q.pop();
            if(Tnode->left!=NULL) q.push(Tnode->left); 
            if(Tnode->right!=NULL) q.push(Tnode->right); 
            temp.push_back(Tnode->data);
        }
        ans.push_back(temp);
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
    vector<vector<int>>vec=s.levelorder(temp);
    for(auto it:vec)
    {
      for(auto it1:it)
      {
        cout<<it1<<" ";
      }
      cout<<endl;
    } 
    return 0;
}