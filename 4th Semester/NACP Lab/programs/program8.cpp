#include <iostream>
#include <algorithm>
using namespace std;
int sum;

bool areDuplicates (int **arr, int N) {
    int i, j;
    int *b = new int[N*N];
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) 
            b[i*N+j] = arr[i][j];
    }
    sort(b, b+N*N);
    for (i=0; i<N*N-1; i++)
        if (b[i] == b[i+1] && b[i] > 0)
            return true;
    return false;
}

int rowSum (int **arr, int N) {
    int i, j;
    long sum_row = 0, prev_sum_row = 0;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) 
            sum_row += arr[i][j];
        if (i!= 0 && sum_row != prev_sum_row)
            return 0;
        prev_sum_row = sum_row;
        sum_row = 0;
    }
    cout<<"\nThe sum of the rows is: "<<prev_sum_row;
    return prev_sum_row;
}

int colSum (int **arr, int N) {
    int i, j;
    long sum_col = 0, prev_sum_col = 0;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) 
            sum_col += arr[j][i];
        if (i!= 0 && sum_col != prev_sum_col)
            return 0;
        prev_sum_col = sum_col;
        sum_col = 0;
    }
    cout<<"\nThe sum of the columns is: "<<prev_sum_col;
    return prev_sum_col;
}

int diagSum (int **arr, int N) {
    int i, j;
    long diag1 = 0, diag2 = 0;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            if (i == j)
                diag1 += arr[i][j];
            if (i + j == N-1)
                diag2 += arr[i][j];
        }
    }
    if (diag1 != diag2)
        return 0;
    cout<<"\nThe sum of the diagonals is: "<<diag1<<endl;
    return diag1;
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    int N;
    cout<<"\nEnter the order of the matrix: ";
    cin>>N;

    int **A = new int*[N];
    for (int i=0; i<N; i++) {
        A[i] = new int[N];
    }

    cout<<"\nEnter the elements of the matrix:\n";
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin>>A[i][j];
        }
    }

    // magic square condition check: no duplicates
    if (areDuplicates(A, N)) {
        cout<<"\nThe matrix cannot be a magic square.";
        return 0;
    }

    // magic square condition check: sum of rows and columns and diagonals are same
    sum = N*(N*N+1)/2;

    if (rowSum(A, N) == 0 || colSum(A, N) == 0 || diagSum(A, N) == 0) {
        cout<<"\nThe matrix is not a magic square.";
        return 0;
    }
    cout<<"\nThe matrix is a magic square.";

    return 0;
}