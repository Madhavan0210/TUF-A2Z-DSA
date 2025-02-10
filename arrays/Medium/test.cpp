#include<bits\stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s="I ate chicken";
    int n=s.length();
    int maxi=INT_MIN;
    int j=-1;
    int cnt=0;
    int start=0;
    for(int i=0;i<=n;i++)
    {
        if(s[i] != ' ' && i!=n)
        {
           if(cnt==0) start=i;;
           cnt++;
        }
        else
        {
            if(cnt>=maxi) 
            {
                maxi=cnt;
            }
            cnt=0;
        }
    }
    cout<<"start:"<<start<<endl;
    cout<<"maxi:"<<maxi<<endl;
    while(maxi>0)
    {
        cout<<s[start++];
        maxi--;
    }
    return 0;
}