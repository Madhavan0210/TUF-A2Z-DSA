#include<bits\stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    int opened=0;
    int maxi=INT_MIN;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            opened++;
            maxi=max(maxi,opened);
        } 
        if(s[i]==')') opened--;
    }
    cout<<"Count:"<<maxi;
    return 0;
}