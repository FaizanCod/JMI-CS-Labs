#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    int n, N = 2, i, j, k;
    // N is the degree of the polynomial to be fitted
    cout<<"\nEnter the number of data points: ";
    cin>>n;
    double *x = new double[n];
    double *y = new double[n];

    // to store values of sum(x^1), sum(x^2), ..., sum(x^2N)
    double *X = new double[2*N + 1];
    // to store values of sum(y), sum(xy), sum(x^2*y) ..., sum(x^N*y)
    double *Y = new double[N + 1];

    cout<<"\nEnter the data points:\n";
    for (i=0; i<n; i++) {
        cout<<"\nEnter x"<<i+1<<": ";
        cin>>x[i];
        cout<<"Enter y"<<i+1<<": ";
        cin>>y[i];
    }

    for (i=0; i<2*N+1; i++) {
        X[i] = 0;
        for (int j=0; j<n; j++)
            X[i] += pow(x[j],i);
    }
    // normal matrix to store equations
    double B[N+1][N+2];
    // to store the values of the coefficients
    double a[N+1];

    for (i=0; i<=N; i++) {
        for (j=0; j<=N; j++) 
            B[i][j] = X[i+j];           // building the normal matrix by storing corresponding coeffs at right positions except last column
    }

    for (i=0; i<N+1; i++) {
        Y[i] = 0;
        for (j=0; j<n; j++)
            Y[i] += pow(x[j],i)*y[j];
    }

    for (i=0; i<=N; i++)
        B[i][N+1] = Y[i];               // loading values of y on last column
    N=N+1;                              // for N degree we get N+1 equations 

    for (i=0; i<N; i++) {
        for (k=0; k<N; k++) {
            if (B[i][i] < B[k][i]) {
                for (j=0; j<=N; j++) {
                    double temp = B[i][j];
                    B[i][j] = B[k][j];
                    B[k][j] = temp;
                }
            }
        }
    }

    for (i=0; i<N-1; i++) {
        for (k=i+1; k<N; k++) {
            double temp = B[k][i]/B[i][i];
            for (j=0; j<=N; j++)
                B[k][j] = B[k][j] - temp*B[i][j];
        }
    }

    for (i=N-1; i>=0; i--) {
        a[i] = B[i][N];                         //make the variable to be calculated equal to the rhs of the last equation
        for (j=0; j<N; j++)
            if (j != i)
                a[i] = a[i] - B[i][j]*a[j];     //then subtract all the lhs values except the coefficient of the variable whose value is being calculated
        a[i] = a[i]/B[i][i];                    //now finally divide the rhs by the coefficient of the variable to be calculated
    }

    cout<<"\nThe values of the coefficients are as follows:\n";
    for (i=0; i<N; i++)
        cout<<setprecision(4)<<fixed<<"x^"<<i<<" = "<<a[i]<<endl;            // Print the values of x^0,x^1,x^2,x^3,....    
    cout<<"\nHence the fitted Polynomial is given by:\ny =";
    for (i=0; i<N; i++) {
        if (i==0)
            cout<<setprecision(4)<<fixed<<" ("<<a[i]<<")x^"<<i;
        else
            cout<<setprecision(4)<<fixed<<" + ("<<a[i]<<")x^"<<i;
    }
    cout<<endl;

    return 0;
}