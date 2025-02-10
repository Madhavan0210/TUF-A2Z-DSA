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
    int left=0,right=0;
    long long sum=vec[0];
    int maxlen=0;
    while(right<n)
    {
        while(left<=right && sum>k)
        {
            sum-=vec[left];
            left++;
        }
        if(sum==k)
        {
            maxlen=max(maxlen,right-left+1);
        }
        right++;
        if(right<n) sum+=vec[right];
    }
    cout<<"Maxlen:"<<maxlen;
    return 0;
}