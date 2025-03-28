#include<bits\stdc++.h>
using namespace std;
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
  void rev(string &s)
  {
    int start=0,end=s.size()-1;
    while(start<=end)
    {
        char temp=s[start];
        s[start]=s[end];
        s[end]=temp;
        start++;
        end--;
    }
  }
  //changing brackets 
  void cbrackets(string &s)
   {
     for(int i=0;i<s.size();i++)
     {
        if(s[i]==')') s[i]='(';
        else if(s[i]=='(') s[i]=')';
     }
   }
  int priority(char ch)
  {
   if(ch=='^') return 3;
   else if(ch=='*' || ch=='/') return 2;
   else if(ch=='+'|| ch=='-') return 1;
   return -1;
  }
  string infixtoprefix(string s)
  {
    rev(s);
    cout<<s<<endl;
    cbrackets(s);
    cout<<s<<endl;
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
            if(s[i]=='^')
            {
                while(!st.empty()&& priority(s[i])<=priority(st.top()))
                {
                    ans+=st.top();
                    st.pop();
                }
            }
            else
            {
                while(!st.empty() && priority(s[i])<priority(st.top()))
                {
                    ans+=st.top();
                    st.pop();
                }
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
    rev(ans);
    return ans;
}     
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    getline(cin,s);
    Solution s1;
    cout<<s1.infixtoprefix(s);
    return 0;
}