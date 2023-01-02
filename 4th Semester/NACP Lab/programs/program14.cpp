#include <iostream>
using namespace std;

void display (int a[]) {
    cout<<"\nArray elements:\n";
    for (int i=0; i<6; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void BubbleSort(int *a) {
    int temp, f;
    for (int i=0; i<6; i++) {   
        f = 1;
        cout<<"\n\nPASS "<<i+1<<endl;
        for (int j=i+1; j<7; j++) {        //need not check for already settled heavier elements 
            if (a[i]>a[j]) {
                f=0;                         //this statement will only execute if the array is unsorted
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
            display(a);
        }
        if (f==1)                           //if the array is sorted checking will terminate
            break;                             //early termination bubble sort
    }
}

int main() {
    // for 7 elements
    int a[7] = {15, 9, 11, 7, 12, 1, 6};
    display(a);
    BubbleSort(a);
    return 0;
}