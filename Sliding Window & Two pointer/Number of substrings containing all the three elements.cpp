#include<bits\stdc++.h>
using namespace std;
class Solution{
 public:
 int NSubstrings(string s)
 {
  int cnt=0;
  int hash[3]={-1,-1,-1};
  for(int i=0;i<s.length();i++)
  {
      hash[s[i]-'a']=i;
      cnt=cnt+(1+min(hash[0],min(hash[1],hash[2])));
  }
  return cnt;

 }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    getline(cin,s);
    Solution s1;
    cout<<s1.NSubstrings(s);
    return 0;
}