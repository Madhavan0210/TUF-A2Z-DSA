#include<bits\stdc++.h>
using namespace std;
void reverse(int arr[],int start,int end)
{
    while(start<=end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ind=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
        {
            ind=i;
            break;
        }
    }
    for(int i=n-1;i>=ind;i--)
    {
        if(arr[i]>arr[ind])
        {
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr,ind+1,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    
}