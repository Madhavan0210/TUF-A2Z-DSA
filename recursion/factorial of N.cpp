#include<bits\stdc++.h>
using namespace std;
int fact(int i)
{
    if(i==0) return 1;
    return i*fact(i-1);
}
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int n;
cin>>n;
cout<<fact(n);
}