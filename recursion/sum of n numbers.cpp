#include<bits\stdc++.h>
using namespace std;
void tsum(int i,int sum)
{
    if(i<1)
    {
        cout<<sum;
     return;
    }
    tsum(i-1,sum+i);
}
int fsum(int i)
{
    if(i==0) return 0;
    return i+fsum(i-1);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int sum=0;
    cout<<fsum(n);
}