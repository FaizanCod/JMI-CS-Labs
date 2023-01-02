#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    int n, N, i, j, k;
    // n is the degree of the polynomial to be fitted
    cout<<"\nEnter the number of data points: ";
    cin>>N;
    double x[N], y[N];

    cout<<"\nEnter the data points:\n";
    cout<<"\nEnter x values:\n";
    for (i=0; i<N; i++)
        cin>>x[i];
    cout<<"\nEnter y values:\n";
    for (i=0; i<N; i++)
        cin>>y[i];
    cout<<"\nEnter the degree of the polynomial: ";
    cin>>n;
    // to store values of sum(x^1), sum(x^2), ..., sum(x^2N)
    double X[2*n+1];

    for (i=0; i<2*n+1; i++) {
        X[i] = 0;
        for (j=0; j<N; j++)
            X[i] += pow(x[j],i);
    }
    // normal matrix to store equations
    double B[n+1][n+2];
    // to store the values of the coefficients
    double a[n+1];

    for (i=0; i<=n; i++) {
        for (j=0; j<=n; j++) 
            B[i][j] = X[i+j];           // building the normal matrix by storing corresponding coeffs at right positions except last column
    }

    // to store values of sum(y), sum(xy), sum(x^2*y) ..., sum(x^N*y)
    double Y[n + 1];

    for (i=0; i<n+1; i++) {
        Y[i] = 0;
        for (j=0; j<N; j++)
            Y[i] += pow(x[j],i)*y[j];
    }

    for (i=0; i<=n; i++)
        B[i][n+1] = Y[i];               // loading values of y on last column
    n=n+1;                              // for N degree we get N+1 equations 

    for (i=0; i<n; i++) {
        for (k=i+1; k<n; k++) {
            if (B[i][i] < B[k][i]) {
                for (j=0; j<=n; j++) {
                    double temp = B[i][j];
                    B[i][j] = B[k][j];
                    B[k][j] = temp;
                }
            }
        }
    }

    for (i=0; i<n-1; i++) {
        for (k=i+1; k<n; k++) {
            double temp = B[k][i]/B[i][i];
            for (j=0; j<=n; j++)
                B[k][j] = B[k][j] - temp*B[i][j];
        }
    }

    for (i=n-1; i>=0; i--) {
        a[i] = B[i][n];                         //make the variable to be calculated equal to the rhs of the last equation
        for (j=0; j<n; j++)
            if (j != i)
                a[i] = a[i] - B[i][j]*a[j];     //then subtract all the lhs values except the coefficient of the variable whose value is being calculated
        a[i] = a[i]/B[i][i];                    //now finally divide the rhs by the coefficient of the variable to be calculated
    }

    cout<<"\nThe values of the coefficients are as follows:\n";
    for (i=0; i<n; i++)
        cout<<setprecision(4)<<fixed<<"x^"<<i<<" = "<<a[i]<<endl;            // Print the values of x^0,x^1,x^2,x^3,....    
    cout<<"\nHence the fitted Polynomial is given by:\ny =";
    for (i=0; i<n; i++) {
        if (i==0)
            cout<<setprecision(4)<<fixed<<" ("<<a[i]<<")x^"<<i;
        else
            cout<<setprecision(4)<<fixed<<" + ("<<a[i]<<")x^"<<i;
    }
    cout<<endl;

    return 0;
}