#include <iostream>
using namespace std;
#define MAX 5
class queue {
    private:
    int a[MAX];
    int front,rear;
    public:
    queue(){
        front=-1;
        rear=-1;
    }
    int empty(){
        if(front==-1&&rear==-1)
        return(1);
        else
        return(0);
    }
    int full()
    {
        if(rear==MAX-1)
        return(1);
        else
        return(0);
    }
    void enqueue(int x)
    {
        if(front==-1&&rear==-1)
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }
        a[rear]=x;
    }
    int dequeue()
    {
        int x=a[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front++;
        }
        return(x);
    }
    int peek()
    {
        return(a[front]);
    }
    void display()
    {
        for (int i=front;i<=rear;i++)
        cout<<a[i]<<endl;
    }
};
    int main() {
    int x;
    queue q;

    q.enqueue(999);
    q.enqueue(888);
    q.enqueue(777);
    q.enqueue(666);
    q.enqueue(555);
    q.enqueue(444);
    
    q.display();

    if (!q.empty()) {
        x = q.dequeue();
        cout << endl << "Removed" << x;
    }
    
    q.display();

    x = q.peek();
    cout << endl << "Top Element is:" << x;

    return 0;
    }
    /*Removed0
Top Element is:0*/