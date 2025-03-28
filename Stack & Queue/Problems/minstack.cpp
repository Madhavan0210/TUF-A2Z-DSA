#include<bits\stdc++.h>
using namespace std;
class Minstack
{
  public:
   stack<long long>s;
   long long mini=INT_MAX;
   int newval=0;
   void push(int val)
   {
     if(s.empty())
     {
      s.push(val);
      mini=val;
     }
     else if(mini>val)
     {
        newval=(2*val)-mini;
        s.push(newval);
        mini=val;
     }
     else
     {
        s.push(val);
     }
   }
    void pop()
    {
        if(mini>s.top())
        {
            int prev=(2*mini)-newval;
            mini=prev;
            s.pop();
        }
        else s.pop();
    }
    void display()
    {
        stack<long long>temp=s;
        while(!temp.empty())
        {
            cout<<temp.top()<<" ";
            temp.pop();
        }
        cout<<endl;
    }
    void getmini()
    {
        cout<<mini<<endl;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Minstack m;
    m.push(12);
    m.push(15);
    m.push(10);
    m.display();
    m.getmini();
    m.pop();
    m.getmini();
    m.push(8 );
    m.getmini();
    m.display();
    return 0;
}
