#include<bits\stdc++.h>
using namespace std;
void f(int i,int n)
{
  if(i>n) return;
  f(i+1,n);
  cout<<i<<" ";  
}
int main()
{
   freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    f(1,n);
    return 0;
}
