#include<bits\stdc++.h>
using namespace std;
void combinations(int ind,int arr[],int target,vector<int>&vec,vector<vector<int>>&ans,int n)
{
    if(ind==n)
    {
        if(target==0)
        {
            ans.push_back(vec);
        }
        return;
    }
    if(arr[ind]<=target)
    {
        vec.push_back(arr[ind]);
        combinations(ind,arr,target-arr[ind],vec,ans,n);
         vec.pop_back();
    }
    combinations(ind+1,arr,target,vec,ans,n);
}
void comb2(int ind,int arr[],int target,vector<int>&vec,vector<vector<int>>&ans,int n)
{
    if(target==0)
    {
        ans.push_back(vec);
        return;
    }
    for(int i=ind;i<n;i++)
    {
    if(i>ind && arr[i]==arr[i-1]) continue;
    if(arr[i]>target) break;
    vec.push_back(arr[i]);
    comb2(i+1,arr,target-arr[i],vec,ans,n);
    vec.pop_back();
    }
}
int main()
{
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int target=7;
     vector<int>vec;
     vector<vector<int>>ans;
    combinations(0,arr,target,vec,ans,n);
    for(auto it:ans)
    {
        for(auto it1 : it) 
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
    return 0;
}