#include<bits\stdc++.h>
using namespace std;
int partition(int a[],int n,int m)
{
  int pivot=a[n];
  int start=n;
  int end=m;
  while(start<end)
  {
    while(a[start]<=pivot) start++;
    while(a[end]>pivot) end--;
    if(start<end)
    {
        swap(a[start],a[end]);
    }
  }
  swap(a[n],a[end]);
  return end;
}
void quicksort(int arr[],int n,int m)
{
    if(n<m) 
    {
        int loc=partition(arr,n,m);
        for(int i=0;i<8;i++) cout<<arr[i]<<" ";
         cout<<endl;
        quicksort(arr,n,loc-1);
        quicksort(arr,loc+1,m);
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int arr[8]={7,6,10,5,9,1,15,7};
    for(int i=0;i<8;i++) cout<<arr[i]<<" ";
    cout<<endl;
    int n=0;
    int m=7;
    quicksort(arr,n,m);
    cout<<endl;
    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}