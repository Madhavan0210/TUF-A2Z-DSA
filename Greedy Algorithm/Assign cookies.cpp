#include<bits\stdc++.h>
using namespace std;
/*
Tc-o(nlogn+mlogm)sorting+o(n)
sc-o(1)
*/
class Solution{
 public:
 int AssignCookies(vector<int>&greed,vector<int>&cookies)
 {
    int l=0,r=0;
    sort(greed.begin(),greed.end());
    sort(cookies.begin(),cookies.end());
    while(l<greed.size() && r<cookies.size())
    {
       if(cookies[r]>=greed[l])
       {
        l++;
       }
       r++;
    }
    return l;
 }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>greed;
    vector<int>cookies;
    int n;
    cin>>n;
    int m;
    cin>>m;
    int val=0;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        greed.push_back(val);
    }
    for(int i=0;i<m;i++)
    {
        cin>>val;
        cookies.push_back(val);
    }
    Solution s;
    cout<<s.AssignCookies(greed,cookies);
    return 0;
}