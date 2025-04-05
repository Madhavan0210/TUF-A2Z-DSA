#include<bits\stdc++.h>
using namespace std;
class Solution
{
 public:
 vector<int> stockspanner(int arr[],int n)
 {
    stack<pair<int,int>>st;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
      while(!st.empty() && st.top().first<=arr[i]) st.pop();
      ans.push_back(i-(st.empty()?-1:st.top().second));
      st.push({arr[i],i});
    }
    return ans;
 }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    vector<int>vec=s.stockspanner(arr,n);
    for(auto it:vec) cout<<it<<" ";
    return 0;
}