#include<bits\stdc++.h>
using namespace std;
class Solution{
 public:
 int Nplatforms(vector<int>&arr,vector<int>&dep)
 {
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int i=0,j=0;
    int cnt=0;
    int maxlen=0;
    while(i<arr.size())
    {
        if(arr[i]<dep[j])
        {
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
        maxlen=max(maxlen,cnt);
    }
    return maxlen;
 }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>arr={900,945,955,1100,1500,1800};
    vector<int>dep={920,1200,1130,1150,1900,2000};
    Solution s;
    cout<<s.Nplatforms(arr,dep);
    return 0;
}