#include<bits\stdc++.h>
using namespace std;
bool isomorphic(string s,string c)
{
    char map_s[128]={0};
    char map_t[128]={0};
    for(int i=0;i<s.size();i++)
    {
        if(map_s[s[i]]!=map_t[c[i]]) return false;
        map_s[s[i]]=i+1;
        map_t[c[i]]=i+1;
    }
    return true;
}
int main()
{
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    string c;
    cin>>c;
    cout<<isomorphic(s,c);
    return 0;
}