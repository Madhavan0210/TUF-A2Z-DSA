#include<bits\stdc++.h>
using namespace std;
int moorsvoting(int arr[],int n)
{
   int el=0;
   int cnt=0;
   for(int i=0;i<n;i++)
   {
    if(cnt==0)
    {
        el=arr[i];
        cnt=1;
    }
    else if(arr[i]==el) cnt++;
    else cnt--;
   }
   return el;
}
int main()
{
   freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=moorsvoting(arr,n);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ans) cnt++;
    }
    cout<<cnt<<endl;
    if(cnt>n/2) cout<<"Answer:"<<ans;
    else cout<<"No";
    return 0;
}