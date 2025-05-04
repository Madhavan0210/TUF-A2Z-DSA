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
        sum+=vec[r];
        while(sum>goal)
        {
            sum-=vec[l];
            l++;
        }
        cnt=cnt+(r-l+1);
        r++;
    }
    return cnt;
 }
 int numsubarrayswithsum(vector<int>&vec,int goal)
 {
    return Subarrcount(vec,goal)-Subarrcount(vec,goal-1);
 }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>vec;
    int n;
    cin>>n;
    int val;
    int goal=2;
    for(int i=0;i<n;i++)  
    {
        cin>>val;
        vec.push_back(val);
    }
    Solution s;
    cout<<s.numsubarrayswithsum(vec,goal);
    return 0;
}