#include<bits\stdc++.h>
using namespace std;
void printsub(int ind,int arr[],vector<int>&vec,vector<vector<int>>&ans,int n)
{
    if(ind==n)
    {
        
        if(vec.size()==0) 
        {
            ans.push_back(vec);
        }
        else 
        {
         ans.push_back(vec);
        }
        return;
    }
    vec.push_back(arr[ind]);
    printsub(ind+1,arr,vec,ans,n);
    vec.pop_back();
    printsub(ind+1,arr,vec,ans,n);

}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>vec;
    vector<vector<int>>ans;
    printsub(0,arr,vec,ans,n);
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