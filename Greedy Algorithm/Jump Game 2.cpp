#include<bits\stdc++.h>
using namespace std;
class Solution{
  public:
  int Jumpgame(vector<int>&vec)
  {
    int jumps=0,l=0,r=0;
    cout<<vec.size()<<endl;
    while(r<vec.size()-1)
    {
        int farthest=0;
        for(int ind=l;ind<=r;ind++)
        {
            farthest=max(ind+vec[ind],farthest);
        }
        l=r+1;
        r=farthest;
        jumps++;
    }
    return jumps;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>vec={2,3,1,4,1,1,1,2};
    Solution s;
    cout<<s.Jumpgame(vec);
    return 0;
}