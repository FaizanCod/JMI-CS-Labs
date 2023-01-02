#include <iostream>
using namespace std;
int N;                  //to store max size

void display (int a[], int n) {
    cout<<"\nArray elements:\n";
    for (int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int insert (int *a, int size, int ele, int pos=1) {
    int index=pos-1;
    if (size == N)
     cout<<"OverFlow! Array reached maximum limit...\n";
    else if(index < 0) {
        cout<<"\nPlease enter a valid position to be inserted\n";
        return size;
    }
    else if(index > (size-1)) {
        cout<<"\nPlease enter a valid position to be inserted\n";
        return size;
    }
    else if (index == 0) {
        for (int i=size-1; i>=0; i--)
            a[i+1]=a[i];  
        a[0]=ele;
        size++;
    }
    else if (index == (size-1)) {
        a[size]=ele;
        size++;
    }
    else {
        for (int i=size-1; i>=index; i--)
            a[i+1]= a[i];
        a[index]=ele;
        size++;
    }
    return size;
}

int deletion (int *a, int size, int pos=1) {
    int index=pos-1;                //index=1 pos=2 size=4
    if (size==0)
        cout<<"UnderFlow! Deletion cannot proceed since array has zero size...\n";
    else if(index<0) {
        cout<<"\nPlease enter a valid position to be deleted\n";
        return size;
    }
    else if (index > (size-1)) {
        cout<<"\nPlease enter a valid position to be deleted\n";
        return size;
    }
    else if (index == 0) {
        for (int i=0; i<size; i++)
         a[i]=a[i+1];
        size--;
    }
    else if (index = (size-1))
        size--;
    else {
        for (int i=index; i<size-1; i++)    //i=1 a[1]=a[2] i=2 a[2]=a[3]
            a[i]=a[i+1];
        size--;
    }
    return size;
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    int size, ele, pos, ch;
    B:
    cout<<"Enter the max size of the array: ";
    cin>>N;
    int *a = new int[N];
    cout<<"\nEnter the size of the initial array: ";
    cin>>size;
    cout<<"Enter the elements of the array: ";
    if (size < N)
        for (int i=0; i<size; i++)
            cin>>a[i];
    else {
        cout<<"\nArray cannot have greater size than max size. Try again!\n";
        goto B;
    } 
    
    while (1) {
        A:
        cout<<"\n\nMENU:\n1. Insert element at beginning";
        cout<<"\n2. Insert element at end";
        cout<<"\n3. Insert element at a given position";
        cout<<"\n4. Delete element at beginning";
        cout<<"\n5. Delete element at end";
        cout<<"\n6. Delete element at a given position";
        cout<<"\n7. Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch (ch) {
            case 1: cout<<"\nEnter element to be inserted: ";
                    cin>>ele;
                    size=insert(a,size,ele);
                    display(a, size);
                    break;
            case 2: cout<<"\nEnter element to be inserted: ";
                    cin>>ele;
                    size=insert(a,size,ele,size);
                    display(a, size);
                    break;
            case 3: cout<<"\nEnter element to be inserted: ";
                    cin>>ele;
                    cout<<"\nEnter position at which element to be inserted: ";
                    cin>>pos;
                    size=insert(a,size,ele,pos);
                    display(a, size);
                    break;
            case 4: cout<<"\nDeleting element at the beginning...\n";
                    size=deletion (a,size);
                    display (a,size);
                    break;
            case 5: cout<<"\nDeleting element at the end...\n";
                    size=deletion (a,size,size);
                    display (a,size);
                    break;
            case 6: cout<<"\nEnter the position at which element to be deleted: ";
                    cin>>pos;
                    size=deletion (a,size,pos);
                    display (a,size);
                    break;
            case 7: exit(0);
            default: cout<<"Wrong choice entered! Try again! ";
                      goto A; 
        }
    }
    return 0;
}