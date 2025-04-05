#include<bits\stdc++.h>
using namespace std;
class Solution
{
 public: 
 string removekdigits(string s,int k)
 {
    stack<char>st;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && k>0 && (st.top()-'0')>(s[i]-'0'))
        {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }
    //k==N
    if(st.empty()) return "0";
    //remaining k
    while(k>0) 
    {
        st.pop();
        k--;
    }
   //adding stack to string
    string ans="";
    while(!st.empty())
    {
      ans+=st.top();
      st.pop();
    }
     //zero removal
    while(ans.size()!=0 && ans.back()=='0')
    {
        ans.pop_back();
    }
    reverse(ans.begin(),ans.end());
    return ans;
 }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    int k;
    cin>>k;
    int n=s.size();
    Solution l;
    cout<<l.removekdigits(s,k);
    return 0;
}