#include<bits\stdc++.h>
using namespace std;
int odd(string s)
{
    int n=s.size()-1;
    int index=-1;
    for(int i=n;i>=0;i--)
    {   
        if((s[i]-'0')%2!=0) 
        {
            index=i;
            break;
        }
    }
    return index;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    int index=-1;
    int ans=odd(s);
    for(int i=0;i<=ans;i++) cout<<s[i];
    return 0;
}