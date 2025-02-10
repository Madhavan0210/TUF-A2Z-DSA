#include<bits\stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int maxi=INT_MIN;
    vector<int>ans;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]>maxi)
        {
           ans.push_back(arr[i]);
           maxi=max(maxi,arr[i]);
        }
        
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}