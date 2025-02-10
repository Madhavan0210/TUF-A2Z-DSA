#include<bits\stdc++.h>
using namespace std;

int main()
{
   freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int vec[n];
    int m;
    cin>>m;
    int arr[m];
    for(int i=0;i<n;i++) cin>>vec[i];
    for(int i=0;i<m;i++) cin>>arr[i];
    //two pointer approach
    int i=0,j=0;
    vector<int> ans;
    while(i<n && j<m)
    {
        if(vec[i]<=arr[j])
        {
       if(ans.size()==0 || ans.back()!=vec[i]) ans.push_back(vec[i]);
        i++;
        }
        else
        {
          if(ans.size()==0 || ans.back()!=arr[j])  ans.push_back(arr[j]);
        j++;
        }
        
    }
    //n
    while(i<n)
    {
       if(ans.back()!=vec[i])  ans.push_back(vec[i]);
        i++;
    }
    //m
    while(j<m)
    {
       if(ans.back()!=arr[j])  ans.push_back(arr[j]);
        j++;
    }
    //cout
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}