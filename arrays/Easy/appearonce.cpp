#include<bits\stdc++.h>
using namespace std;

int main()
{
   freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int vec[n];
    for(int i=0;i<n;i++) cin>>vec[i];
    map<int,int>mpp;
    for(int i=0;i<n;i++) mpp[vec[i]]++;
    for(auto it:mpp)
    {
        if(it.second==1) cout<<"Answer:"<<it.first<<endl;
    }
    return 0;
}