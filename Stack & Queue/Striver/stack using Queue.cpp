#include<bits\stdc++.h>
using namespace std;
class Queue
{
 private:
 vector<int>vec;
 int start,end;
 int s;
 public:
 Queue()
 {
    start=0;
    end=-1;
    s=0;
 }
 void push(int val)
 {
        vec.push_back(val);
        end++;
        s++;
    
 }
 void pop()
 {
    if(s==0) return;
    start++;
    s--;
 }
 int top()
 {
  return vec[start];
 }
 void display()
 {
    for(int i=start;i<=end;i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
 }
 int size()
 {
    return s;
 }
};
class Stack
{
    private:
    Queue q;
    public:
    void push(int val)
    {
        q.push(val);
        int a=q.size();
        for(int i=1;i<a;i++)
        {
            q.push(q.top());
            q.pop();
        }
    }
    void top()
    {
        cout<<q.top()<<endl;
    }
    void pop()
    {
        q.pop();
    }
    void display()
    {
        q.display();
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Stack s;
    s.push(1);
    s.top();
    s.push(2);
    s.top();
    s.push(3);
    s.top();
    s.push(4);
    s.top();
    s.push(5);
    s.top();
    s.display();
    s.pop();
    s.display();
    return 0;
}