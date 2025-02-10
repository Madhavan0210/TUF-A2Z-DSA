#include<bits\stdc++.h>
using namespace std;
bool palindromecheck(string s,int index,int i)
{
  int start=index;
  int end=i;
  while(start<=end)
  {
    if(s[start++]!=s[end--]) return false;

  }
  return true;
}
void solve(int ind,string s,vector<string>&temp,vector<vector<string>>&ans)
{
    if(ind==s.size())
    {
        ans.push_back(temp);
    }
    for(int i=ind;i<s.size();i++)
    {
        if(palindromecheck(s,ind,i))
        {
            temp.push_back(s.substr(ind,i-ind+1));
            solve(i+1,s,temp,ans);
            temp.pop_back();
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s="aabb";
    vector<vector<string>>ans;
    vector<string>temp;
    solve(0,s,temp,ans);
    for(auto it:ans)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
    return 0;
}