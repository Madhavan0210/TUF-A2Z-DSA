#include<bits\stdc++.h>
using namespace std;
//using struct
struct Node{
   int data;
   Node *left,*right;
   Node(int val)
   {
    data=val;
    left=right=NULL;
   }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    struct Node *root=new Node(5);
    root->left=new Node(1);
    root->right=new Node(3);
    root->left->right=new Node(4);
    return 0;
}