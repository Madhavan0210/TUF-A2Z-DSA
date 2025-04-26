#include<bits\stdc++.h>
using namespace std;
class Solution
{
public:
 int MaxConsecutiveones(vector<int>&vec,int k)
 {
    int r=0,l=0;
    int maxlen=0;
    int len=0;
    int zeros=0;
    int n=vec.size();
    while(r<n)
    {
        if(vec[r]==0) zeros++;
        if(zeros>k)
        {
           if(vec[l]==0) zeros--;
           l++; 
        }
        if(zeros<=k) 
        {
            len=r-l+1;
            maxlen=max(maxlen,len);
        }
        r++;
    }
    return maxlen;
 }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>vec={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    Solution s;
    cout<<s.MaxConsecutiveones(vec,k);
    return 0;
}