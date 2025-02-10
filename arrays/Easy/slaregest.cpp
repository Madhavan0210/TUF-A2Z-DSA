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
    int largest=vec[0];
    int slargest=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(vec[i]>largest)
        {
           slargest=largest;
           largest=vec[i]; 
        }
        else if(vec[i]>slargest && vec[i]<largest) slargest=vec[i];
    }
    cout<<"Largest:"<<largest<<endl;
    cout<<"slargest:"<<slargest<<endl;
   return 0;
}