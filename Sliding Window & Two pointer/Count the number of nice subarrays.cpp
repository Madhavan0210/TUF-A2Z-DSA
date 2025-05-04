#include<bits\stdc++.h>
using namespace std;
class Solution{
    public:
    int Subarrcount(vector<int>&vec,int goal)
 {
    int l=0,r=0,cnt=0;
    int sum=0;
    while(r<vec.size())
    {
        if(goal<0) return 0;
        sum+=vec[r]%2;
        while(sum>goal)
        {
            sum-=vec[l]%2;
            l++;
        }
        cnt=cnt+(r-l+1);
        r++;
    }
    return cnt;
 }
    int countsubarray(vector<int>&vec,int k)
    {
        return Subarrcount(vec,k)-Subarrcount(vec,k-1); 
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>vec={1,1,2,1,1};
    int k=3;
    Solution s;
    cout<<s.countsubarray(vec,k);
    return 0;
}