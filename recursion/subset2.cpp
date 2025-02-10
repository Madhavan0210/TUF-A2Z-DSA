#include<bits\stdc++.h>
using namespace std;
void subset(int ind,vector<int>&vec,vector<int>&temp,vector<vector<int>>&ans)
{
    ans.push_back(temp);
    for(int i=ind;i<vec.size();i++)
    {
        if(i>ind && vec[i]==vec[i-1]) continue;
        temp.push_back(vec[i]);
        subset(i+1,vec,temp,ans);
        temp.pop_back();
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>vec={1,2,2,2,3,3};
    vector<int>temp;
    vector<vector<int>>ans;
    subset(0,vec,temp,ans);
    for(auto it:ans)
    {
        for(auto it1:it) cout<<it1<<" ";
        cout<<endl;
    }
}