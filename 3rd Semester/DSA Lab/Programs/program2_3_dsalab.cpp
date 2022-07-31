#include <iostream>
using namespace std;

void display (int a[], int n)
{
    for (int i=0; i<n; i++)
     cout<<a[i]<<" ";
}

void BubbleSort (int *a, int n)
{
    int temp;
    for (int i=0; i<n-1; i++)
    {
        cout<<"\nPASS "<<i+1<<endl;
        for (int j=0; j<(n-i); j++)         
        {
            if (a[j]>a[j+1])
            {                        
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            cout<<"\nIteration "<<j+1<<": ";
            display(a,n);
            cout<<endl;
        }               
    }
}

void BubbleSort_earlyterminate (int *a, int n)
{
    int temp,f=1;
    for (int i=0; i<n-1; i++)
    {
        f=1;
        cout<<"\n\nPASS "<<i+1<<endl;
        for (int j=0; j<(n-i); j++)         
        {
            if (a[j]>a[j+1])
            {
                f=0;                        
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            cout<<"\nIteration "<<j+1<<": ";
            display(a,n);
            cout<<endl;
        }
        if (f==1)                       //early termination bubble sort
        {
            cout<<"\nArray has been sorted with early termination of the loop...";
            break;
        }                  
    }
}

int main()
{
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n\n";
    int n;
    while (1)
    {
        cout<<"\nEnter the size of the array (press 0 to exit): ";
        cin>>n;
        if (n==0)
         exit(0);
        int a[n];
        cout<<"\nEnter the elements of the array: ";
        for (int i=0; i<n; i++)
         cin>>a[i];
        int temp,f=1,ch;
        A:
        cout<<"\nEnter choice: \n1. Bubble sort. \n2. Bubble sort using Early termination. \n3. Exit.\n";
        cin>>ch;
        switch (ch)
        {
            case 1: BubbleSort(a,n);
                    break;
            case 2: BubbleSort_earlyterminate(a,n);
                    break;
            case 3: exit(0);
            default: cout<<"Wrong choice entered! Try again! ";
                     goto A; 
        }
        cout<<"\nArray after sorting: ";
        display(a,n);
        cout<<endl;
    }
    
    return 0;
}