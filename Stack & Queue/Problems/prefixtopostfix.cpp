#include<bits\stdc++.h>
using namespace std;
class Solution {
    public:
    stack<string>st;
      string preToPost(string s) {
          int n=s.size();
      int i=n-1;
      while(i>=0)
      {
          if((s[i]>='A' && s[i]<='z')|| (s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')) 
          {
             string temp=string(1,s[i]);
              st.push(temp);
          }
          else
          {
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string con=t1+t2+string(1,s[i]);
            st.push(con);
          }
          i--;
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
  cout<<s1.preToPost(s);
  return 0;
}