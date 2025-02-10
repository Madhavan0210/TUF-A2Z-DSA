#include<bits\stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n=5;
     int arr[n]={0,0,5,3,5};
     int k=5;
     int count[k+1]={0};
     for(int i=0;i<n;i++)
     {
        count[arr[i]]++;
     }
     for(int i=1;i<=k;i++)
     {
        count[i]=count[i]+count[i-1];
     }
     int dup[n];
     for(int i=n-1;i>=0;i--)
     {
        dup[--count[arr[i]]]=arr[i];
     }
       for(int i=0;i<n;i++) cout<<dup[i]<<" ";
     cout<<endl;
     for(int i=0;i<n;i++) arr[i]=dup[i];
     for(int i=0;i<n;i++) cout<<arr[i]<<" ";
     return 0;
}