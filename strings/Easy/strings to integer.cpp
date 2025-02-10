#include<bits\stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    //string s;
    getline(cin,s);
    if(s.length()==0) cout<<"0";
    int n=s.length();
    int i=0;
    int sign=+1;
    long ans=0;
    while(i<n && s[i] == ' ') 
    {
        i++;
       // cout<<"hi"<<endl;
    }
    s=s.substr(i);
    if(s[0] == '-') sign=-1;
    i=(s[0]=='+'||s[0]=='-')?1:0;
    while(i<n)
    {
        if(s[i]==' ' || !isdigit(s[i])) break;
        ans=ans*10+(s[i]-'0');
        if(sign==-1 && -1*ans<INT_MIN) cout<<"value:"<<INT_MIN<<endl;
        if(sign==1 && ans>INT_MAX) cout<<"value:"<<INT_MAX<<endl;
        i++;
    }
    cout<<"value:"<<ans*sign;
    return 0;
}