#include<bits\stdc++.h>
using namespace std;
class Solution{
    public:
    int countsubarry(vector<int>&vec,int k)
    {
        int l=0,r=0,cnt=0;
        map<int,int>mpp;
        while(r<vec.size())
        {
            mpp[vec[r]]++;
            while(mpp.size()>k)
            {
                mpp[vec[l]]--;
                if(mpp[vec[l]]==0) mpp.erase(vec[l]);
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int subarrwithksize(vector<int>&vec,int k)
    {
      return countsubarry(vec,k)-countsubarry(vec,k-1);
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>vec={1,2,1,3,4};
    int k=3;
    Solution s;
    cout<<s.subarrwithksize(vec,k);
    return 0;
}