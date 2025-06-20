#include<bits\stdc++.h>
using namespace std;
class Solution{
    public:
    int MinimumCoins(int v)
    {
        int demo[]={1,2,5,10,20,50,100,500,1000};
        int n=9;
        int cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            while(v>=demo[i])
            {
                v-=demo[i];
                cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int v;
    cin>>v;
    Solution s;
    cout<<s.MinimumCoins(v);
    return 0;
}