#include<bits\stdc++.h>
using namespace std;
class Solution{
  public:
  int candy(vector<int>&vec)
  {
    int sum=1,peak=1,down=1,r=1;
    int n=vec.size();
    while(r<n)
    {
        if(vec[r]==vec[r-1]) 
        {
            sum++;
            r++;
        }
        while(r<n && vec[r]>vec[r-1])
        {
            peak++;
           sum+=peak;
           r++;
        }
        while(r<n && vec[r-1]>vec[r])
        {
            sum+=down;
            down++;
            r++;
        }
        if(peak<down) sum+=(down-peak);
    }
    return sum;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>vec={0,2,4,7,6,5,4,3,2,1,1,1,2,3,4,2,1,1,1};
    Solution s;
    cout<<s.candy(vec);
    return 0;
}