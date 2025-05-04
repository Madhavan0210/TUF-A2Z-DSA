#include<bits\stdc++.h>
using namespace std;
class Solution{
  public:
  bool validparenthesis(string &s)
  {
    int mini=0,maxi=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            mini++;
            maxi++;
        }
        else if(s[i]==')')
        {
            mini--;
            maxi--;
        }
        else{
            mini--;
            maxi++;
        }
        if(mini<0) mini=0;
        if(maxi<0) return false;
    }
    return (mini==0);
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s="()*)*()";
    Solution s1;
    cout<<s1.validparenthesis(s);
    return 0;
}