    #include<bits\stdc++.h>
    using namespace std;
    class Node
    {
        public:
        int data;
        Node* next;

        Node()
        {
            data=0;
            next=NULL;
        }
        Node(int data1)
        {
            data=data1;
            next=NULL;
        }
    };
    class Linkedlist
    {
    private:
    Node *head,*front,*rear;
    public:
      Linkedlist()
      {
        head=front=rear=NULL;
      }
      void enqueue(int data1)
      {
        Node* newnode=new Node(data1);
        if(head==NULL)
        {
            head=rear=front=newnode;
        }
        else 
        {
            rear->next=newnode;
            newnode->next=front;
            rear=newnode;
        }
      }
      void dequeue()
      {
        if(front==NULL)
        {
            cout<<"Underflow"<<endl;
        }
        else if(front->next==front)
        {
            delete(front);
            cout<<"Empty"<<endl;
        }
        else
        {
            Node* temp=front;
            front=front->next;
            rear->next=front;
            delete(temp);
        }
      }
      void display()
      {
        Node* temp=front;
        while(temp->next!=front)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
      }
    };
    int main()
    {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
      Linkedlist l1;
      l1.enqueue(1);
      l1.enqueue(2);
      l1.enqueue(3);
      l1.enqueue(4);
      l1.enqueue(5);
      l1.display();
      l1.dequeue();
      l1.display();
      return 0;
    }