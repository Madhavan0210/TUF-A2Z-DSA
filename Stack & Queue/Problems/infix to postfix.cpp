#include<bits\stdc++.h>
using namespace std;
class Solution
{
  private:
  stack<char>st;
  string ans;
  int i=0;
  public:
  Solution()
  {

  }
  int priority(char ch)
  {
   if(ch=='^') return 3;
   else if(ch=='*' || ch=='/') return 2;
   else if(ch=='+'|| ch=='-') return 1;
   return -1;
  }
  void infixtopostfix(string s)
  {
    while(i<s.size())
    {
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')) ans+=s[i];
        else if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')')
        {
            while(!s.empty() && st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && (priority(s[i])<=priority(st.top())) && s[i]!='^')
            {
               ans+=st.top();
               st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
  }
  void display()
  {
    cout<<ans;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    getline(cin,s);
    Solution s1;
    s1.infixtopostfix(s);
    s1.display();
    return 0;
}