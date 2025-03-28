#include<bits\stdc++.h>
using namespace std;
class Solution
{
 private:
 stack<string>st;
 public:
 string postfixtoinfix(string s)
 {
    int n=s.size();
    int i=0;
    while(i<n)
    {
        if((s[i]>='A' && s[i]<='z')|| (s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')) 
        {
            st.push(to_string(s[i]));
        }
        else
        {
          string t1=st.top();
          st.pop();
          string t2=st.top();
          st.pop();
          string con='('+t2+s[i]+t1+')';
          st.push(con);
        }
        i++;
    }
    return st.top();
 }
};
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  string s;
  getline(cin,s);
  Solution s1;
  cout<<s1.postfixtoinfix(s);
  return 0;
}