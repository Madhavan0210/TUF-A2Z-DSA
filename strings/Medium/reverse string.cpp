#include<bits\stdc++.h>
using namespace std;
string rev(string &word)
{
    int end=word.size()-1;
    int start=0;
    while(start<end)
    {
     char c=word[start];
     word[start]=word[end];
     word[end]=c;
     start++;
     end--;
    }
    return word;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    getline(cin,s);
    int start=0;
    int n=s.length();
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    string ans="";
    for(int i=0;i<n;i++)
    {
        int start=-1;
        string word="";
        while(i<n && s[i]!=' ')
        {
            word+=s[i];
            if(start==-1) start=i;
            i++;
        }
        rev(word);
        cout<<word<<endl;
        if(word.length()>0)
        ans+=" "+word;
    }
    cout<<ans<<endl;
    return 0;  
}