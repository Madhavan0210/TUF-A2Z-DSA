#include<bits\stdc++.h>
using namespace std;
class Solution
{
    public:
  int celebrityproblem(vector<vector<int>>&mat,int n,int m)
  {
    int top=0;
    int down=m-1;
    while(top<down)
    {
     if(mat[top][down]==1) top++;
     else if(mat[down][top]==1) down--;
     else
     {
        top++;
        down--;
     }
    }
    if(top>down) return -1;
    for(int i=0;i<n;i++)
    {
        if(i==top) continue;
        if(mat[top][i]==0 && mat[i][top]==1) continue;
        else return -1;
    }
    return top;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<vector<int>>mat={{0,1,1,0},
    {1,1,1,1},{0,1,0,0},{1,1,0,0}};
   Solution s;
   cout<<s.celebrityproblem(mat,4,4);
    return 0;
}