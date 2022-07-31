#include <iostream>
using namespace std;

const int LIMIT=20;
int queue[LIMIT], front=-1, rear=-1;

int isEmpty ()
{
    if (front==-1 && rear==-1)
        return 1;
    else 
        return 0;
}

int isFull ()
{
    if (rear==(LIMIT-1))
        return 1;
    else
        return 0;
}

void display ()
{
    if (isEmpty()==1)
        cout<<"\nQueue is empty! Nothing to display\n";
    else
    {
        for (int i=front; i<rear; i++)
            cout<<queue[i]<<" <- ";
        cout<<queue[rear]<<endl;
    }
}

int size ()
{
    if (isEmpty()==1)
        return 0;
    else
        return (rear-front+1);
}

void front_rear ()
{
    if (isEmpty()==1) 
        cout<<"\nQueue is empty..."<<endl;
    else
    {
        cout<<"\nFront element is: "<<queue[front];
        cout<<"\nRear element is: "<<queue[rear]<<endl;
    }
    
}

void enqueue (int n)
{
    if (isFull()==1)
        cout<<"\nQueue Overflow! Maximum limit (20) reached..."<<endl;
    if (isEmpty()==1)
    {
        front=rear=0;
        queue[front]=n;
        display();
    }
    else
    {
        rear++;
        queue[rear]=n;
        display();
    }
}

void dequeue ()
{
    if (isEmpty()==1)
        cout<<"\nQueue Underflow! Queue is empty..."<<endl;
    if (front == rear)
    {
        cout<<"\nDequeuing front element: "<<queue[front]<<endl;
        front=rear=-1;
        display();
    }
    else
    {
        cout<<"\nDequeuing front element: "<<queue[front]<<endl;
        front++;
        display();
    }
}

int main()
{
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    int ch,n;
    while (true)
    {
        A:
        cout<<"\nMENU:\n1. Enqueue\n2. Dequeue\n3. Display front and rear elements\n4. Check if queue is full\n5. Check if queue is empty\n6. Size of the queue\n7. Display queue\n8. Exit\n";
        cin>>ch;
        switch (ch)
        {
        case 1: cout<<"\nEnter the element to be enqueued: ";
                cin>>n;
                enqueue(n);
                break;
        case 2: dequeue();
                break;
        case 3: front_rear();
                break;
        case 4: if (isFull()==1)
                    cout<<"\nQueue is full!\n";
                else
                    cout<<"\nQueue is not full.\n";
                break;
        case 5: if (isEmpty()==1)
                    cout<<"\nQueue is empty!\n";
                else
                    cout<<"\nQueue is not empty.\n";
                break;
        case 6: cout<<"\nSize of the queue is: "<<size()<<endl;
                break;
        case 7: cout<<"\nQueue elements: "<<endl;
                display();
                break;
        case 8: exit(0);
        default: cout<<"\nWrong choice! Enter again...\n";
                 goto A;
        }
    }
    return 0;
}