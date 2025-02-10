#include<bits\stdc++.h>
using namespace std;
int printsub(int ind,int arr[],int s,vector<int>&vec,vector<vector<int>>&ans,int sum,int n)
{
    if(ind==n)
    {
        if(s==sum)
        {
            return 1;
        }
         else return 0;
    }
   s+=arr[ind];
   int l=printsub(ind+1,arr,s,vec,ans,sum,n) ;
   s-=arr[ind];
   int r=printsub(ind+1,arr,s,vec,ans,sum,n);
   return l+r;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int sum=3; 
    vector<int>vec;
    vector<vector<int>>ans;
    cout<<printsub(0,arr,0,vec,ans,sum,n);
    return 0;
}