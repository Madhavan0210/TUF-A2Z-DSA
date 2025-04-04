#include<bits\stdc++.h>
using namespace std;
class Solution
{
 public:
 int optimal(vector<int>&arr)
  {
    int maxi=0;
    stack<int>st;
    int nse=0,pse=0;
    int element=0;
    for(int i=0;i<arr.size();i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
          element=st.top();
          st.pop();
          nse=i;
          pse=st.empty()?-1:st.top();
          maxi=max(maxi,(nse-pse-1)*arr[element]);
        }
        st.push(i);
    }
    while(!st.empty())
    {
        nse=arr.size();
        element=st.top();
        st.pop();
        pse=st.empty()?-1:st.top();
        maxi=max(maxi,(nse-pse-1)*arr[element]);
    }
    return maxi;
  }
 int maximalrec(vector<vector<int>>&arr,int n,int m)
 {
    vector<vector<int>>presum(n,vector<int>(m,0));
   
    for(int i=0;i<m;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=arr[j][i];
            if(arr[j][i]==0) sum=0;
            presum[j][i]=sum;
        }
    }
    int maxarea=0;
    for(int i=0;i<n;i++) maxarea=max(maxarea,optimal(presum[i]));
    return maxarea;
 }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<vector<int>>vec={
        {1,0,1,0,1},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };
    Solution s;
    cout<<s.maximalrec(vec,4,5);
    return 0;
}