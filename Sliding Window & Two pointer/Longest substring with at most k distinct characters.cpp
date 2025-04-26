#include<bits\stdc++.h>
using namespace std;
class Solution
{
public:
  int Lsubstring(string s,int k)
  {
    int l=0,r=0,maxlen=0,len=0;
    unordered_map<char,int>mpp;
    while(r<s.length())
    {
     mpp[s[r]]++;
     while(mpp.size()>k)
     {
        mpp[s[l]]--;
        if(mpp[s[l]]==0) mpp.erase(s[l]);
        l++;
     }
     if(mpp.size()<=k)
     {
        len=r-l+1;
        maxlen=max(len,maxlen);
     }
     r++;
    }
    return maxlen;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s="aaabbccd";
    int k=2;
    Solution s1;
    cout<<s1.Lsubstring(s,k);
    return 0;
}