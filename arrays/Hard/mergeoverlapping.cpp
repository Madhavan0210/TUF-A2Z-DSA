#include<bits\stdc++.h>
using namespace std;
vector<vector<int>>mergeoverlapping(vector<vector<int>>arr)
{
    int n=arr.size();
    vector<vector<int>>ans;
    for(int i=0;i<n;i++)
    {
        if(ans.empty()||arr[i][0]>ans.back()[1]) ans.push_back(arr[i]);
        else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}
int main()
{
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<vector<int>>ans={{1,3},{2,4},{2,3},{2,8}};
    vector<vector<int>>res=mergeoverlapping(ans);
      int n=res.size();
    int m=res[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}