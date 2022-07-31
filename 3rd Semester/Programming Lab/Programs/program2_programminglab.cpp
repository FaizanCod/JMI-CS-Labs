#include <iostream>
using namespace std;
int N;                  //Global variable for max size

//FUNCTION DEFINITIONS
void display (int a[], int n)
{
    cout<<"\nArray elements:\n ";
    for (int i=0; i<n; i++)
    cout<<a[i]<<" ";
    cout<<endl;
}

int insertion_beg (int arr[], int ele, int size)
{
  if(size == N){
    cout<<"\nCannot Insert: OverFlow !\n";
    return size;
  }

  for(int i = size-1; i>=0; i--)
  {
    arr[i+1] = arr[i];                                    //shifting elements to the right
  }
  arr[0] = ele;
  size++;
  return size;
}

int insertion_end (int arr[], int ele, int size)
{
  if(size == N){
    cout<<"\nCannot Insert: OverFlow !\n";
    return size;
  }

  arr[size] = ele;
  size++;
  return size;
}

int insertion_pos(int arr[], int ele, int pos, int size)
{
  if(size == N){
    cout<<"\nCannot Insert: Overflow !\n";
    return size;
  }

  if(pos<0){
    cout<<"\nPlease enter a valid position\n";
    return size;
  }
  else if(pos>size-1){
    cout<<"\nCannot insert outside the bounds. Please enter a valid position\n";
    return size;
  }

  for(int i = size-1; i>=pos; i--){
    arr[i+1] = arr[i];                                                    //shifting elements to the right
  }
  arr[pos] = ele;
  size++;

  return size;
}

int deletion_beg(int arr[], int size)
{
  if(size==0){
    cout<<"\nUnderFlow! Empty array!\n";
    return size;
  }
  for(int i = 0; i<size-1; i++){                        //shifting elements to left
    arr[i] = arr[i+1];
  }
  size--;
  return size;
}

int deletion_end(int arr[], int size)
{
  if(size==0){
    cout<<"\nUnderFlow! Empty array!\n";
    return size;
  }
  size--;
  return size;
}

int deletion_pos(int arr[], int pos, int size)
{
  if(size==0){
    cout<<"\nUnderFlow! Empty array!\n";
    return size;
  }

  if(pos<0)
  {
    cout<<"\nPlease enter a valid position to be deleted\n";
    return size;
  }
  else if(pos>size-1){
    cout<<"\nPlease enter a valid position to be deleted\n";
    return size;
  }

  for(int i = pos; i<size-1; i++){                          //shifting elements to the left
    arr[i] = arr[i+1];
  }
  size--;
  return size;
}

int main()
{
    int ch, ele, index;
    int size=0;                                       //empty array
    cout<<"FAIZAN CHOUDHARY\n20BCS021\n";
    cout<<"\nEnter the maximum size of the array: ";
    cin>>N;
    int a[N];
    

    while (1)
    {
        A:
        cout<<"\n\nMENU:\n1. Insert element at beginning";
        cout<<"\n2. Insert element at end";
        cout<<"\n3. Insert element at a given index";
        cout<<"\n4. Delete element at beginning";
        cout<<"\n5. Delete element at end";
        cout<<"\n6. Delete element at a given index";
        cout<<"\n7. Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch (ch)
        {
            case 1: cout<<"\nEnter element to be inserted at beginning: ";
                    cin>>ele;
                    size= insertion_beg(a,ele,size);
                    display (a,size);
                    break;
            case 2: cout<<"\nEnter element to be inserted at end: ";
                    cin>>ele;
                    size= insertion_end (a,ele,size);
                    display (a,size);
                    break;
            case 3: cout<<"\nEnter element to be inserted at a given index: ";
                    cin>>ele;
                    cout<<"\nEnter index at which insertion to be carried out: ";
                    cin>>index;
                    size= insertion_pos (a,ele,index,size);
                    display (a,size);
                    break;
            case 4: cout<<"\nDeleting at the beginning...\n ";
                    size= deletion_beg (a,size);
                    display (a,size);
                    break;
            case 5: cout<<"\nDeleting at end...\n ";
                    size= deletion_end (a,size);
                    display (a,size);
                    break;
            case 6: cout<<"\nEnter index at which deletion to be carried out: ";
                    cin>>index;
                    size= deletion_pos (a,index,size);
                    display (a,size);
                    break;
            case 7: exit(0);
            default: cout<<"Wrong choice entered! Try again! ";
                     goto A; 
        }
    }
    return 0;
}


