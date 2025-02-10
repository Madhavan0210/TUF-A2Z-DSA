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
    int large=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(vec[i]>large) large=vec[i];
    }
    cout<<"Largest Element:"<<large<<endl;
    return 0;
}
