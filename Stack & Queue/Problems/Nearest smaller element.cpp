#include<bits\stdc++.h>
using namespace std;
class Solution
{
   public:
   vector<int> nse(int arr[],int n)
   {
    vector<int>ans(n,0);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top()>=arr[i])
        {
            st.pop();
        }
        if(st.empty()) ans[i]=-1;
        else ans[i]=st.top();
        st.push(arr[i]);
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
    vector<int> vec=s.nse(arr,n);
    for(int i=0;i<vec.size();i++) cout<<vec[i]<<" ";
    return 0;
}