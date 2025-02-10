#include<bits\stdc++.h>
using namespace std;

int freqmax(int freq[])
{
    int count=INT_MIN;
    for(int i=0;i<26;i++)
    {
        count=max(freq[i],count);
    }
   return count;
}
int freqmin(int freq[])
{
    int count=INT_MAX;
    for(int i=0;i<26;i++)
    {
        if(freq[i]!=0)
        count=min(freq[i],count);
    }
   return count;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s("aabac");
    int n=s.length();
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int freq[26]={0};
        for(int j=i;j<n;j++)
        {
          freq[s[j]-'a']++;
          int beauty=freqmax(freq)-freqmin(freq);
          sum+=beauty;
        }
    }
    cout<<sum;
    return 0;
}