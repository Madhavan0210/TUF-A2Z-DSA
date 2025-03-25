#include<bits\stdc++.h>
using namespace std;
class Stackk
{
 private:
   int s[5];
   int top=-1;
   public:
   void push(int arr[])
   {
    for(int i=0;i<5;i++)
    {
        top++;
       s[i]=arr[i]; 
    }
   }
   void pop()
   {
    if(top<0) cout<<"underflow"<<endl;
    else
    {
      cout<<"poped val:"<<s[top]<<endl;  
      top--;
    }
   }
   void display()
   {
    for(int i=top;i>=0;i--  ) cout<<s[i]<<" ";
   }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int arr[]={1,2,3,4,5};
    Stackk s;
    s.push(arr);
    s.pop();
    s.display();
    return 0;
}