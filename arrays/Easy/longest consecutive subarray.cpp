#include<bits\stdc++.h>
using namespace std;

int main()
{
   freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int k;
    cin>>k;
    int vec[n];
    for(int i=0;i<n;i++) cin>>vec[i];
    map<long long,int>presum;
    long long sum=0;
    int maxlen=0;
    for(int i=0;i<n;i++)
    {
        sum+=vec[i];
        if(sum==k)
        {
            maxlen=max(maxlen,i+1);
        }
        long long rem=sum-k;
        if(presum.find(rem)!=presum.end())
        {
           int len=i-presum[rem];
           maxlen=max(maxlen,len); 
        }
        if(presum.find(rem)==presum.end())
        {
            presum[sum]=i;
        }
    }
    cout<<"maxlen:"<<maxlen;
    return 0;
}