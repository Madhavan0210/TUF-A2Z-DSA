#include<bits\stdc++.h>
using namespace std;
void solve2(int i,int j,vector<vector<int>>&m,vector<string>&ans,vector<vector<int>>&v,string move,int n,int d[],int dj[])
{
    if(i==n-1 && j==n-1)
    {
        ans.push_back(move);
        return ;
    }
    string dir="DLRW";
    for(int ind=0;ind<n;ind++)
    {
     int nexti=i+d[ind];
     int nextj=j+dj[ind];
     if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !v[nexti][nextj] && m[nexti][nextj]==1)
     {
        v[i][j]=1;
        solve2(nexti,nextj,m,ans,v,move+dir[ind],n,d,dj);
        v[i][j]=0;
     }
    }
}
void solve(int i,int j,vector<vector<int>> &m,vector<string>&ans,vector<vector<int>>&v,string move,int n)
{
    if(i==n-1 && j==n-1)
    {
        ans.push_back(move);
        return;
    }
    //down
    if(i+1<n && !v[i+1][j] && m[i][j]==1)
    {
        v[i][j]=1;
        solve(i+1,j,m,ans,v,move+'D',n);
        v[i][j]=0;
    }
    //left
     if(j-1>=0 && !v[i][j-1] && m[i][j]==1)
    {
        v[i][j]=1;
        solve(i,j-1,m,ans,v,move+'L',n);
        v[i][j]=0;
    }
    //right
    if(j+1<n && !v[i][j+1] && m[i][j]==1)
    {
        v[i][j]=1;
        solve(i,j+1,m,ans,v,move+'R',n);
        v[i][j]=0;
    }
    //up
    if(i-1>=0 && !v[i-1][j] && m[i][j]==1)
    {
        v[i][j]=1;
        solve(i-1,j,m,ans,v,move+'U',n);
        v[i][j]=0;
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<vector<int>>m={
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    int n=4;
    vector<string>ans;
    int d[]={1,0,0,-1};
    int d1[]={0,-1,1,0};
    vector<vector<int>>hashh(n,vector<int>(n,0));
    solve2(0,0,m,ans,hashh,"",n,d,d1);
for(auto it:ans) cout<<it<<" ";
    return 0;
}