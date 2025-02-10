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
    int i=0;
    //two pointer approach
    for(int j=1;j<n;j++)
    {
        if(vec[j]!=vec[i])
        {
           vec[i+1]=vec[j];
           i++; 
        }
    }
    int m=i+1;
    for(int i=0;i<m;i++) cout<<vec[i]<<" ";
    return 0;
}