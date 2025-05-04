#include<bits\stdc++.h>
using namespace std;
class Solution{
  public:
   long shortestjobfirst(vector<int>&p)
   {
    sort(p.begin(),p.end());
    int wt=0;
    int t=0;
    for(int i=0;i<p.size();i++)
    {
        wt+=t;
        t+=p[i];
    }
    return (wt/p.size());
   }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>p={4,3,7,1,2};
    Solution s;
    cout<<s.shortestjobfirst(p);
    return 0;
}