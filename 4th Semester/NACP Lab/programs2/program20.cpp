#include <iostream>
using namespace std;
int l, m, n, p;
int **C = new int*[l];

void multiply (int **A, int **B, int l, int m, int n) {
    for (int i=0; i<l; i++) {                   //for accessing the rows of A
        for (int j=0; j<n; j++) {               //for accessing the columns of B
            C[i][j]=0;
            for (int k=0; k<m; k++)             //to traverse and multiply
                C[i][j]+=A[i][k]*B[k][j];
        }
    }
}

void display (int **A, int l, int m) {
    for (int i=0; i<l; i++) {
        for (int j=0; j<m; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    cout<<"\nEnter the number of rows and columns for matrix A: ";
    cin>>l>>m;
    cout<<"\nEnter the number of rows and columns for matrix B: ";
    cin>>p>>n;
    if (p != m) {
        cout<<"\nMatrix not compatible for multiplication! ";
        return 0;
    }
    int **A = new int*[l];
    int **B = new int*[m];
    for (int i=0; i<l; i++) {
        A[i] = new int[m];
        C[i] = new int[n];
    }
    for (int i=0; i<m; i++)
        B[i] = new int[n];

    cout<<"\nEnter the elements of matrix A row-wise:\n";
    for (int i=0; i<l; i++) {
        for (int j=0; j<m; j++)
            cin>>A[i][j];
    }

    cout<<"\nEnter the elements of matrix B row-wise:\n";
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++)
            cin>>B[i][j];
    }
    cout<<"\nInput matrix A:\n";
    display(A, l, m);
    cout<<"\nInput matrix B:\n";
    display(B, m, n);
    
    multiply (A, B, l, m, n);
    cout<<"\nOutput matrix C (after multiplication):\n";
    display(C, l, n);
    cout<<endl;

    return 0;
}