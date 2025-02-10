#include<bits\stdc++.h>
using namespace std;
void permutation(int ind,int arr[],int freq[],vector<int>&vec,vector<vector<int>>&ans,int n)
{
    if(vec.size()==n)
    {
        ans.push_back(vec);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!freq[i])
        {
            freq[i]=1;
            vec.push_back(arr[i]);
            permutation(i,arr,freq,vec,ans,n);
            freq[i]=0;
            vec.pop_back();
        }
    }
}
//swapping
void optimal(int ind,vector<int>&arr,vector<vector<int>>&ans,int n)
{
    if(ind==n)
    {
        ans.push_back(arr);
        return;
    }
    for(int i=ind;i<n;i++)
    {
        swap(arr[ind],arr[i]);
        optimal(ind+1,arr,ans,n);
        swap(arr[ind],arr[i]);
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int>arr;
    int val=0;
    for(int i=0;i<n;i++) 
    {
        cin>>val;
        arr.push_back(val);
    }
    vector<int>vec;
    int freq[n]={0};
    vector<vector<int>>ans;
    //permutation(0,arr,freq,vec,ans,n);
    optimal(0,arr,ans,n);
    for(auto it:ans)
    {
        for(auto it1:it) cout<<it1;
        cout<<endl;
    }
    return 0;
}