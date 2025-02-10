#include<bits\stdc++.h>
using namespace std;
void subset(int ind,int sum,vector<int>&vec,vector<int>&ans,int n)
{
    if(ind==n)
    {
        ans.push_back(sum);
        return;
    }
    //pick
    subset(ind+1,sum+vec[ind],vec,ans,n);
    //not pick
    subset(ind+1,sum,vec,ans,n);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>vec={3,1,2};
    int n=3;
    vector<int>ans;
    int sum=0;
    subset(0,sum,vec,ans,n);
    sort(ans.begin(),ans.end());
    for(auto it:ans) cout<<it<<" ";
    return 0;
}