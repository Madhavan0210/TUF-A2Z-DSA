#include<bits\stdc++.h>
using namespace std;
vector<int> repeatandmissing(vector<int>arr)
{
long long n=arr.size();
//find sn and s2n
long long sn=(n*(n+1))/2;
long long s2n=(n*(n+1)*(2*n+1))/6;
long long s=0,s2=0;
for(int i=0;i<n;i++)
{
    s+=arr[i];
    s2+=(long long)arr[i]*(long long)arr[i];
}
//s-sn
long long val1=s-sn;
long long val2=s2-s2n;
val2=val2/val1;
long long x=(val1+val2)/2;
long long y=x-val1;
return {(int)x,(int)y};
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>arr={1,2,1,3,4,6};
    vector<int>ans=repeatandmissing(arr);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}