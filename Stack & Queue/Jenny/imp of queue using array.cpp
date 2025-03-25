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
            rear=front=0;
            arr[front]=data;
        }
        else if(rear==4)
        {
            cout<<"Overflow"<<endl;
        }
        else
        {
           rear++;
           arr[rear]=data;
        }
        //cout<<front<<endl;
    }
    void dequeue()
    {
        if(front==-1 && rear==-1) 
        {
            cout<<"Underflow"<<endl;
        }
        else if(front==rear)
        {
            front==rear==-1;
            cout<<"Empty"<<endl;
        }
        else
        {
            front++;
        }
    }
    void display()
    {
        while(front<=rear)
        {
            cout<<arr[front]<<" ";
            front++;
        }
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.dequeue();
    q1.dequeue();
    q1.display();    
    return 0;
}