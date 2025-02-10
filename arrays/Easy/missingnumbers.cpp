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
    int sum=(n*(n+1))/2;
    int s=0;
    for(int i=0;i<n-1;i++) 
    {
        s+=vec[i];
    }
    int missing=sum-s;
    cout<<"Missing:"<<missing<<endl;
    return 0;
}