#include<bits\stdc++.h>
using namespace std;
class Solution{
 public:
 int Maxbasket(vector<int>&vec,int k)
 {
    int l=0,r=0;
    int maxlen=0;
    int len=0;
    unordered_map<int,int>mpp;
    while(r<vec.size())
    {
        mpp[vec[r]]++;
        while(mpp.size()>k)
        {
            mpp[vec[l]]--;
            if(mpp[vec[l]]==0) mpp.erase(vec[l]);
            l++;
        }
        if(mpp.size()<=k)
        {
            len=r-l+1;
            maxlen=max(len,maxlen);
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
    int k=2;
    vector<int>vec={3,3,3,1,2,1,1,2,3,3,4};
    Solution s;
    cout<<s.Maxbasket(vec,k);
    return 0;
}