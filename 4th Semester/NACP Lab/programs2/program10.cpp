// Program for Gauss Seidal method
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    double a[10][10], b[10], x[10], y[10];
    int n, q = 0, i = 0, j = 0;

    cout<<"\nEnter number of equations : ";
    cin>>n;

    cout<<"\nEnter coefficient matrix row-wise\n";
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++)
            cin>>a[i][j];
    }

    cout<<"\nEnter values to the right side of equation\n";
    for (i=0; i<n; i++)
        cin>>b[i];
   
    cout<<"\nEntered equations are:\n";
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++)
            cout<<a[i][j]<<"\t";
        cout<<":\t"<<b[i];
        cout<<endl;
    }

    cout<<"\nEnter initial values: \n";
    for (i=0; i<n; i++)
        cin>>x[i];

    cout<<"\nEnter the no. of iteration : ";
    cin>>q;
    while (q > 0) {
        for (i=0; i<n; i++) {
            y[i] = (b[i] / a[i][i]);
            for (j=0; j<n; j++) {
                if (j == i)
                    continue;
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                x[i] = y[i];
            }
            cout<<"\nx["<<i + 1 << "] = "<<setprecision(4)<<fixed<<y[i]<<" ";
        }
        cout<<endl;
        q--;
    }

    return 0;
}