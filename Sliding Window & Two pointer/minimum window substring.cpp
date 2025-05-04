#include<bits\stdc++.h>
using namespace std;
class Solution{
public:
string MinWindow(string s,string t)
{
    int l=0,r=0;
    int minlen=INT_MAX;
    int sind=-1;
    int cnt=0;
    int hash[256]={0};
    for(int i=0;i<t.size();i++) hash[t[i]]++;
    while(r<s.length())
    {
        if(hash[s[r]]>0){
            cnt=cnt+1;
        }
        hash[s[r]]--;
        while(cnt==t.size())
        {
            if(r-l+1<minlen)
            {
                minlen=r-l+1;
                sind=l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0) cnt--;
            l++;
        }
        r++;
    }
    return s.substr(sind,minlen);
}
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    string t="abc";
    Solution a;
    string temp=a.MinWindow(s,t);
    cout<<temp;
    return 0;
}