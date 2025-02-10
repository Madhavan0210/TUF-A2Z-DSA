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
    int smallest=vec[0];
    int ssmallest=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(vec[i]<smallest)
        {
           ssmallest=smallest;
           smallest=vec[i]; 
        }
        else if(smallest<vec[i] && vec[i]<ssmallest) ssmallest=vec[i];
    }
    cout<<"Smallest:"<<smallest<<endl;
    cout<<"ssmallest:"<<ssmallest<<endl;
   return 0;
}