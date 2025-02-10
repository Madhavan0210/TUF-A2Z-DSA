#include<bits\stdc++.h>
using namespace std;
vector<vector<int>> brute(vector<int> arr)
{
    set<vector<int>>st;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(arr[i]+arr[j]+arr[k]==0)
                {
                    vector<int>temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>> better(vector<int> arr)
{
    set<vector<int>>st;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        set<int> hashset;
        for(int j=i+1;j<n;j++)
        {
            int third=-(arr[i]+arr[j]);
                if(hashset.find(third)!=hashset.end())
                {
                    vector<int>temp={arr[i],arr[j],third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>> optimal(vector<int>arr)
{
    int cnt=0;
    vector<vector<int>> ans;
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
       if(i>0 && arr[i]==arr[i-1]) continue;
       int j=i+1;
       int k=n-1;
       while(j<k)
       {
        int sum=arr[i]+arr[j]+arr[k];
        if(sum<0) j++;
        else if(sum>0) k--;
        else
       {
        vector<int>temp= {arr[i],arr[j],arr[k]};
        cnt++;
        ans.push_back(temp);
        j++;
        k--;
        while(j<k && arr[j]==arr[j-1]) j++;
        while(j<k && arr[k]==arr[k+1]) k--;
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
   vector<int>arr={-1,-2,-1,-2,-1,-2,2,2,0,0,2,2,0};
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