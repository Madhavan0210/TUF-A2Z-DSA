#include<bits\stdc++.h>
using namespace std;
void permutation(int ind,vector<int>&vec,int freq[],vector<int>&t,vector<vector<int>>&ans,int n)
{
    if(t.size()==n)
    {
        ans.push_back(t);
    }
    for(int i=0;i<n;i++)
    {
        if(freq[i]==0)
        {
            freq[i]=1;
            t.push_back(vec[i]);
            permutation(i+1,vec,freq,t,ans,n);
            freq[i]=0;
            t.pop_back();
        }
        else cout<<"marked"<<endl;
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>vec={1,2,3};
    int n=3;
    int freq[n]={0};
    vector<int>t;
    vector<vector<int>>ans;
    permutation(0,vec,freq,t,ans,n);
    for(auto it:ans) 
    {
        for(auto it1:it) cout<<it1<<" ";
        cout<<endl;
    }
}