#include<bits\stdc++.h>
using namespace std;
class Solution
{
  public:
  vector<int> AstCollision(int arr[],int n)
  {
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0) ans.push_back(arr[i]);
        else
        {
           while(!ans.empty() && ans.back()>0 && ans.back()<abs(arr[i])) ans.pop_back();
           if(!ans.empty() && ans.back()==abs(arr[i])) ans.pop_back();
           else if(ans.empty() && ans.back()<0) ans.push_back(arr[i]);
        }
    }
    return ans;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int arr[]={4,7,1,1,2,-3,-7,17,15,-16};
    Solution s;
    vector<int>vec=s.AstCollision(arr,10);
    for(auto it:vec) cout<<it<<" ";
    return 0;
}