#include<bits\stdc++.h>
using namespace std;
int main()
{
   freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int arr[5]={1,2,6,3,5};
   
    for(int i=0;i<5;i++)
    {
         int maxi=0;
        for(int j=i;j<5;j++)
        {
            if(arr[j]>maxi) maxi=arr[j];
            cout<<i<<" "<<j<<":"<<maxi;
            cout<<endl;
        }
    }
}