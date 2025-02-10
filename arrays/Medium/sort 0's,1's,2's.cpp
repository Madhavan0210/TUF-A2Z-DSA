#include<bits\stdc++.h>
using namespace std;
void swapping(int arr[],int i,int j)
{
 int temp=arr[i];
 arr[i]=arr[j];
 arr[j]=temp;
}
int main()
{
   freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int vec[n];
    for(int i=0;i<n;i++) cin>>vec[i];
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(vec[mid]==0)
        {
            swapping(vec,low,mid);
            low++;
            mid++;
        }
        else if(vec[mid]==1) mid++;
        else{
            swapping(vec,mid,high);
            high--;
        }
    }
    for(int i=0;i<n;i++) cout<<vec[i]<<" ";
    return 0;
}