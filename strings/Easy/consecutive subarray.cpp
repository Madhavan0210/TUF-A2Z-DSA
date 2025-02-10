#include<bits\stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s("c");
    int ans=0;
    int cnt=1;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]==s[i-1]) cnt++;
        else{
            ans=max(ans,cnt);
            cnt=1;
        }
    }
    ans=max(ans,cnt);
    cout<<"Ans:"<<ans;
    return 0;
}