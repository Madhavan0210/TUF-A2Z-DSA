#include<bits\stdc++.h>
using namespace std;
class Solution
{
 public:
 int Lsubstring(string s)
 {
    int l=0,r=0;
    int maxlen=0;
    int n=s.length();
    int hash[256]={-1};
    int len=0;
    while(r<n)
    {
          
      if(hash[s[r]]!=-1)
       {
        
        if(hash[s[r]]>=l) l=hash[s[r]]+1;
       }
       len=r-l+1;
       maxlen=max(len,maxlen);
       hash[s[r]]=r;
       r++;
    }
    return maxlen;
 }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    getline(cin,s);
    Solution s1;
    cout<<s1.Lsubstring(s);
    return 0;    
}
