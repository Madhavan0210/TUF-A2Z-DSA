#include<bits\stdc++.h>
using namespace std;
class Queue
{
  private:
  int arr[5];
  int front=-1;
  int rear=-1;
  public:
  void enqueue(int data)
  {
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        arr[rear]=data;
    }
    else if((rear+1)%5==front)
    {
        cout<<"FULL"<<endl;
    }
    else
    {
        rear=(rear+1)%5;
        arr[rear]=data;
    }
  }
  void dequeue()
  {
    if(front==-1 && rear==1) cout<<"Underflow"<<endl;
    else if(rear==front) 
    {
        front=rear=-1;
        cout<<"Empty"<<endl;
    }
    else
    {
        front=(front+1)%5;
    }
  }
  void display()
  {
    if(front==-1 && rear==-1) cout<<"Empty"<<endl;
    else
    {
        int i=front;
        while(i!=rear)
        {
           cout<<arr[i]<<" ";
           i=(i+1)%5; 
        }
        cout<<arr[i]<<endl;
    }
  }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(4);
    q.display();
   return 0; 
}