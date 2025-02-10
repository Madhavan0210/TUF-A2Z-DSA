#include<bits\stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    int start=0;
    int maxlen=INT_MIN;
    int n=s.length();
    for(int i=1;i<n;i++)
    {
        int l=i-1;
        int r=i;
        while(l>=0 && r<n)
        {
            
            if(s[l]!=s[r]) break;
            if(s[l]==s[r])
            {
                cout<<"l:"<<l<<"r:"<<r<<endl;
                maxlen=max(maxlen,r-l+1);
                l-=1;
                r+=1;
            }
        }
        l=i-1;
        r=i+1;
        while(l>=0 && r<n)
        {
            
            if(s[l]!=s[r]) break;
            if(s[l]==s[r])
            {
                maxlen=max(maxlen,r-l+1);
                l-=1;
                r+=1;
            }
        } 
        
    }
    cout<<maxlen<<endl;
    while(maxlen>0)
    {
        cout<<s[start++]<<" ";
       maxlen--;
    }
    return 0;
}