#include<bits\stdc++.h>
using namespace std;
class Solution{
  public:
  vector<vector<int>> InsertInterval(vector<vector<int>>&mat,vector<int>interval)
  {
    int i=0;
    int n=7;
    vector<vector<int>>res;
    while(i<n && mat[i][1]<interval[0])
    {
        res.push_back(mat[i]);
        i++;
    }
    while(i<n && mat[i][0]<interval[1])
    {
      interval[0]=min(interval[0],mat[0][i]);
      interval[0]=max(interval[1],mat[1][i]);
    }
    res.push_back(interval);
    while(i<n)
    {
      res.push_back(mat[i]);
      i++;
    }
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<vector<int>>mat={
        {1,2},{3,4},{7,7},{8,10},{12,16}
    };
    int interval[2]={5,6};
    return 0;
}