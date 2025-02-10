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
    int cnt=0;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(vec[i]==1)
        {
            cnt++;
            maxi=max(maxi,cnt);
        }
        else cnt=0;
    }
    cout<<"1s:"<<maxi;
    return 0;
}