#include<bits\stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    getline(cin,s);
    cout<<s<<endl;
    int start=-1;
    int begin=-1;
    int maxi=0;
    int cnt=0,i=0;
    int n=s.length();
    while(i<=n)
    {
        if(s[i]!=' ' && i!=n)
        {
            if(cnt==0) start=i;
            cnt++;
        }
        else
        {
            if(cnt>maxi)
            {
                cout<<"c"<<cnt<<endl;
                cout<<"m"<<maxi<<endl;
                maxi=cnt;
                begin=start;
            }
            cnt=0;
        }
        i++;
    }
   
    while(maxi>0)
    {
      cout<<s[begin++];
      maxi--;  
    }
    return 0;
}