#include<bits\stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>pos,neg;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]); 
    }
    int m=pos.size();
    int k=neg.size();
    if(m>k)
    {
       for(int i=0;i<k;i++)
       {
        arr[i*2]=pos[i];
        arr[2*i+1]=neg[i];
       } 
       int index=k*2;
       for(int i=index;i<m;i++)
       {
        arr[index]=pos[i];
        index++;
       }
    }
    else
    {
       for(int i=0;i<m;i++)
       {
        arr[i*2]=pos[i];
        arr[2*i+1]=neg[i];
       } 
       int index=m*2;
       for(int i=index;i<m;i++)
       {
        arr[index]=neg[i];
        index++;
       }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}