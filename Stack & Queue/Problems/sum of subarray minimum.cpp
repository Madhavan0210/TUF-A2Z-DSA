#include<bits\stdc++.h>
using namespace std;
class Solution
{
    private:
    int mintotal=0;
   public:
   vector<int> findnse(int arr[],int n)
   {
    vector<int>temp(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        temp[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return temp;
   } 
   vector<int> findpse(int arr[],int n)
   {
    vector<int>temp(n);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
        temp[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return temp;
   } 
  
   int tmin(int arr[],int n)
  {
    int mod=(int)(1e9+7);
    vector<int>nse=findnse(arr,n);
    vector<int>pse=findpse(arr,n);
    for(int i=0;i<n;i++)
    {
        int left=i-pse[i];
        int right=nse[i]-i;
        mintotal=(mintotal+((right*left)*1LL*arr[i])%mod)%mod;
    }
    return mintotal;
  }


};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int arr[4]={3,1,2,4};
    Solution s;
    cout<<s.tmin(arr,4);
    return 0;
}