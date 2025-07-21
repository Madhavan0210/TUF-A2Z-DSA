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
  void parentmark(Node *root,unordered_map<Node*,Node*>&parent)
  {
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(temp->left)
        {
            parent[temp->left]=temp;
            q.push(temp->left);
        }
        if(temp->right)
        {
            parent[temp->right]=temp;
            q.push(temp->right);
        }
    }
  }
  int minimumTime(Node* root)
  {
    unordered_map<Node*,Node*>parent;
    parentmark(root,parent);
    map<Node*,bool>visited;
    queue<Node*>q;
    q.push(root);
    visited[root]=true;
    int t=0;
    while(!q.empty())
    {
        t++;
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            Node* temp=q.front();
            q.pop();
            if(temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left]=true;
            }
            if(temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right]=true;
            }
            if(parent[temp] && !visited[parent[temp]])
            {
                q.push(parent[temp]);
                visited[parent[temp->left]]=true;
            }
        }
    }
    return t;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Solution s;
    Node* temp=s.create(); 
    int time=s.minimumTime(temp);
    cout<<time<<endl;
    return 0;
}