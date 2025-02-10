#include<bits\stdc++.h>
using namespace std;

int main()
{
   freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int vec[n];
    for(int i=0;i<n;i++) cin>>vec[i];
    //two pointer approach
    int j=0;
    for(int i=0;i<n;i++)
    {
      if(vec[i]==0)
      {
        j=i;
        break;
      }
    }
    for(int i=j+1;i<n;i++)
    {
        if(vec[i]!=0) 
        {
          vec[j++]=vec[i];
          vec[i]=0;
        }
    }
    for(int i=0;i<n;i++) cout<<vec[i]<<" ";
    return 0;
}