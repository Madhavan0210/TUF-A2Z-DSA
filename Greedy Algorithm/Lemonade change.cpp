#include<bits\stdc++.h>
using namespace std;
class Solution{
  public:
  bool Lchange(vector<int>&bills)
  {
    int five=0,ten=0;
    for(int i=0;i<bills.size();i++)
    {
       if(bills[i]==5) five++;
       else if(bills[i]==10) 
       {
        if(five) five--;
        else return false;
        ten++;
       }
       else{
        if(five && ten) 
        {
            five--;
            ten--;
        }
        else if(five>=3) five-=3;
        else return false;
       }
    }
    return true;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>bills={5,5,5,10,20};
    Solution s;
    cout<<s.Lchange(bills);
    return 0;
}