#include<bits\stdc++.h>
using namespace std;
bool twosum(int arr[],int target,int n)
{
    int left=0,right=n-1;
    while(left<right)
    {
    int sum=arr[left]+arr[right];
    if(sum==target)return true;
    else if(sum<target) left++;
    else right--;
    }
    return false;
}
vector<int> Tsum(int arr[],int target,int n)
{
    map<int,int>mpp;
    for(int i=0;i<n;i++)
    {
        int a=arr[i];
        int more=target-a;
        if(mpp.find(more)!=mpp.end()) return {mpp[more],i};
        mpp[a]=i;
    }
    return {-1,-1};
}
int main()
{
   freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int target;
    cin>>target;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> ans=Tsum(arr,target,n);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}  