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
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(vec[i+1]<vec[i]) 
        {
            flag=1;
            break;
        }
    }
    if(flag==1) cout<<"No";
    else cout<<"Yes";
    return 0;
}