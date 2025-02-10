#include<bits\stdc++.h>
using namespace std;
vector<vector<int>> optimal(vector<int>arr)
{
    int target=8;
    int cnt=0;
    vector<vector<int>> ans;
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
       if(i>0 && arr[i]==arr[i-1]) continue;
       for(int j=i+1;j<n;j++){
        if(j != (i+1) && arr[j] == arr[j-1]) continue;
       int k=j+1;
       int l=n-1;
       while(k<l)
       {
        long long sum=arr[i];
        sum+=arr[j];
        sum+=arr[k];
        sum+=arr[l];
       if(sum==target)
       {
        vector<int>temp = {arr[i],arr[j],arr[k],arr[l]};
        cnt++;
        ans.push_back(temp);
        k++;
        l--;
        while(k<l && arr[k]==arr[k-1]) k++;
        while(k<l && arr[l]==arr[l+1]) l--;
       }
       else if(sum<target) k++;
       else l--;
       }
       }
    }
    cout<<"count:"<<cnt<<endl;
    return ans;
}
int main()
{
   freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   vector<int>arr={2,2,3,3,1,1,2,3,1,5,4,5,4,4};
    vector<vector<int>>res=optimal(arr);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[0].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}