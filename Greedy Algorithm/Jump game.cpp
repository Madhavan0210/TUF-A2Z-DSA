#include<bits\stdc++.h>
using namespace std;
class Solution{
 public:
 bool jumpgame(vector<int>&vec)
 {
    int maxlen=0;
    for(int i=0;i<vec.size();i++)
    {
        if(i>maxlen) return false;
        maxlen=max(maxlen,i+vec[i]);
    }
    return true;
 }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>vec={1,2,4,1,1,0,2,5};
    Solution s;
    cout<<s.jumpgame(vec);
    return 0;
}