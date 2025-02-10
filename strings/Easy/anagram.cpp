#include<bits\stdc++.h>
using namespace std;
bool anagram(string s,string a,int n,int m)
{
map<char,int>mpp;
for(int i=0;i<n;i++)
{
mpp[s[i]]++;
mpp[a[i]]--;
}
for(auto it:mpp)
{
    if(it.second>0) return false;
}
return true;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
string s;
cin>>s;
string a;
cin>>a;
int n=s.size();
int m=a.size();
if(n!=m) cout<<"No";
else cout<<anagram(s,a,n,m);
return 0;
}