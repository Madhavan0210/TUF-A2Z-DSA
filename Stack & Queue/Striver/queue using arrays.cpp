#include<bits\stdc++.h>
using namespace std;
class Queue
{
  private:
  int arr[10];
  int start=-1;
  int end=-1;
  int currsize=0;
  public:
  void push(int val)
  {
    if(currsize==10) cout<<"Full"<<endl;
    else if(currsize==0)
    {
        start=end=0;
        arr[end]=val;
        currsize++;
    }
    else
    {
        end=(end+1)%10;
        arr[end]=val;
        currsize++;
    }
  }
  void pop()
  {
    if(currsize==0) cout<<"empty"<<endl;
    else if(currsize==1) 
    {
        start=end=-1;
        currsize--;
    }
    else
    {
        start=(start+1)%10;
        currsize--;
    }
  }
  void display()
  {
    if(start=-1) return;
    int i=start;
    while(i!=end)
    {
        cout<<arr[i]<<" ";
        i=(i+1)%10;
    }
    cout<<arr[i]<<endl;
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.display();
    return 0;
}