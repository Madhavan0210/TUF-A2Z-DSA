//maximum-minimum
#include<bits\stdc++.h>
using namespace std;
class Solution
{
    private:
    int mintotal=0;
    int maxtotal=0;
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
   vector<int> findnge(int arr[],int n)
   {
    vector<int>temp(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
        temp[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return temp;
   } 
   vector<int> findpge(int arr[],int n)
   {
    vector<int>temp(n);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
        temp[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return temp;
   } 
   int tminmax(int arr[],int n)
  {
    int mod=(int)(1e9+7);
    vector<int>nse=findnse(arr,n);
    vector<int>pse=findpse(arr,n);
    vector<int>pge=findpge(arr,n);
    vector<int>nge=findnge(arr,n);
    for(int i=0;i<n;i++)
    {
        int left=i-pse[i];
        int right=nse[i]-i;
        int mleft=i-pge[i];
        int mright=nge[i]-i;
        mintotal=(mintotal+((right*left)*1LL*arr[i])%mod)%mod;
        maxtotal=(maxtotal+((mright*mleft)*1LL*arr[i])%mod)%mod;
    }
    return maxtotal-mintotal;
  }


};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int arr[4]={3,1,2,4};
    Solution s;
    cout<<s.tminmax(arr,4);
    return 0;
}