#include<bits\stdc++.h>
using namespace std;

int main()
{
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>ans={-1,0,1,-2,3,-1};
    int n=ans.size();
    unordered_map<int,int>mpp;
    int maxi=-1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=ans[i];
        if(sum==0) 
        {
            maxi=i+1;
        }
        else{
          if(mpp.find(sum)!=mpp.end())
          {
            maxi=max(maxi,i-mpp[sum]);
          }
          else
          {
            mpp[sum]=i;
          }
        }
    }
    cout<<"Maxi:"<<maxi<<endl;
    return 0;
}