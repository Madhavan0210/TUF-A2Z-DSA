#include<bits\stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    map<char,int> mpp = {{'I',1},{'V',5},
    {'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int res=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]<s.length() || mpp[s[i]]<mpp[s[i+1]]) res-=mpp[s[i]];
        else res+=mpp[s[i]];
    }
    cout<<res;
    return 0;
}