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
    //kadane's algorithm
    int maxi=INT_MIN;
    int sum=0;
    int start=-1;
    int anss=-1;
    int ansend=-1;
    for(int i=0;i<n;i++)
    {
        if(sum==0) start=i;
        sum+=arr[i];
        
        if(sum>maxi) 
        {
            maxi=sum;
            anss=start;
            ansend=i;
        }
        if(sum<0) sum=0;
    }
    cout<<"Maximum:"<<maxi<<endl;
    cout<<"start:"<<start<<endl;
    cout<<"Anss:"<<anss<<endl;
    cout<<"Ansend:"<<ansend<<endl;
    for(int i=anss;i<=ansend;i++) cout<<arr[i]<<" ";
    return 0;
}