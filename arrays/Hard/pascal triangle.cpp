#include<bits\stdc++.h>
using namespace std;

int main()
{
   freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int res=1;
    cout<<res<<" ";
    for(int i=1;i<n;i++)
    {
        res=res*(n-i);
        res=res/(i);
        cout<<res<<" ";
    }
    return 0;
}