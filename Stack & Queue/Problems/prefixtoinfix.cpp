#include<bits\stdc++.h>
using namespace std;

class Solution {
    private:
stack<string>st;
 public:
   string preToInfix(string s) {
       // Write your code here
       int n=s.size()-1;
   int i=n;
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
         string con='('+t1+string(1,s[i])+t2+')';
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
  cout<<s1.preToInfix(s);
  return 0;
}