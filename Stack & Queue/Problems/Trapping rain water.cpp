#include<bits\stdc++.h>
using namespace std;
class Solution
{
 public:
 int water(int arr[],int n)
  {
    int cnt=0;
    int i=0;
    int lmax=0,rmax=0;
    int l=0,r=n-1;
    while(l<r)
    {
        if(arr[l]<arr[r])
        {
            if(lmax>arr[l]) 
            {
              cnt+=lmax-arr[l];    
            }
            else lmax=arr[l];
            l++;
        }
        else if(arr[r]<arr[l])
        {
            if(rmax>arr[r])
            { 
                cnt+=rmax-arr[r];
            }
            else rmax=arr[r];
            r--;
        }
        else
        {
            lmax=max(lmax,arr[l]);
            l++;
        }
    }
    return cnt;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int arr[12]={0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout<<s.water(arr,12);
    return 0;
}