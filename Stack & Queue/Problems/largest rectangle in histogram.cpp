#include<bits\stdc++.h>
using namespace std;
class Solution{
 public:
 //area of rectangle=l*b
   vector<int> NSE(int arr[],int n)
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
   vector<int> PSE(int arr[],int n)
   {
    vector<int>temp(n);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
       while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
       temp[i]=st.empty()?-1:st.top();
       st.push(i);
    }
   
    return temp;
   }
  int lreactangle(int arr[],int n)
  {
    vector<int>nse=NSE(arr,n);
    vector<int>pse=PSE(arr,n);
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        int l=i-pse[i];
        int r=nse[i]-i;
        int val=((r+l)-1)*arr[i];
        maxi=max(maxi,val);
    }
    return maxi;
  }
  int optimal(int arr[],int n)
  {
    int maxi=0;
    stack<int>st;
    int nse=0,pse=0;
    int element=0;
    for(int i=0;i<n;i++)
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
        nse=n;
        element=st.top();
        st.pop();
        pse=st.empty()?-1:st.top();
        maxi=max(maxi,(nse-pse-1)*arr[element]);
    }
    return maxi;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int arr[8]={3,2,10,11,5,10,6,3};
    Solution s;
    cout<<s.optimal(arr,8);
    return 0;
}