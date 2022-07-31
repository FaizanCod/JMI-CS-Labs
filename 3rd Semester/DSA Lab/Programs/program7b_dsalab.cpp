#include <iostream>
using namespace std;

struct stack
{
    int info;
    struct stack *next;
};
struct stack *ptr,*top=NULL,*p;

int isEmpty ()
{
    if (top==NULL)
     return 1;
    else 
     return 0;
}

void display ()
{
    if (isEmpty()==1)
     cout<<"\nStack is empty! Nothing to display\n";
    else
    {
        cout<<endl<<top->info<<"  <--"<<endl;
        p=top->next;
        while (p!=NULL)
        {
            cout<<p->info<<endl;
            p=p->next;
        }
    }
}

int size ()
{
    if (isEmpty()==1)
     return 0;
    else
    {
        int count=0;
        for (p=top; p!=NULL; p=p->next)
         count++;
        return count;
    }
}

void peek ()
{
    if (isEmpty()==1) 
     cout<<"\nStack is empty..."<<endl;
    else
     cout<<"\nTop element is: "<<top->info<<endl;
}

void push (int n)
{
    ptr=(struct stack *) malloc (sizeof(struct stack));
    if (ptr==NULL)
    {
        cout<<"\nMemory could not be allocated!\n";
        return;
    } 
    ptr->info=n;
    ptr->next=NULL;         //assign values to the empty dynamic block
    if (top==NULL)          //if the stack is empty initally, directly assign top as ptr
     top=ptr;
    else
    {
        ptr->next=top;      //otherwise assign the value that top points, to ptr and then update the top to hold the address of the new ptr
        top=ptr;
    }
    display();
}

void pop ()
{
    if (isEmpty()==1)
     cout<<"\nStack Underflow! Stack is empty..."<<endl;
    else
    {
        cout<<"\nPopping top element: "<<top->info<<endl;
        top=top->next;
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
        cout<<"\nMENU:\n1. Push into stack\n2. Pop element\n3. Peek top element\n4. Check if stack is empty\n5. Size of the stack\n6. Display stack\n7. Exit\n";
        cin>>ch;
        switch (ch)
        {
        case 1: cout<<"Enter the element to be pushed: ";
                cin>>n;
                push(n);
                break;
        case 2: pop();
                break;
        case 3: peek();
                break;
        case 4: if (isEmpty()==1)
                 cout<<"\nStack is empty!\n";
                else
                 cout<<"\nStack is not empty.\n";
                break;
        case 5: cout<<"\nSize of the stack is: "<<size()<<endl;
                break;
        case 6: cout<<"\nStack elements: "<<endl;
                display();
                break;
        case 7: exit(0);
        default: cout<<"\nWrong choice! Enter again...\n";
                 goto A;
        }
    }
}