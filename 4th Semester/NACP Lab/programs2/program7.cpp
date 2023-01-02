// Double integration using Simpson's 1/3rd Rule
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double f (double x, double y=1) {
    double a = sin(x*y) / (1 + x*y);
    return a;
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    int nx, ny, i, j;
    double a, b, c, d, h, k, z[20][20], ax[20];
    double ans;
    cout<<"\nEnter the limits of integration\nInitial limit for outer integral a = ";
    cin>>a;
    cout<<"Final limit for outer integral b = ";
    cin>>b;
    cout<<"\nInitial limit for inner integral c = ";
    cin>>c;
    cout<<"Final limit for inner integral d = ";
    cin>>d;
    cout<<"\nEnter the no. of subintervals for outer integral nx = ";
    cin>>nx;
    cout<<"Enter the no. of subintervals for inner integral ny = ";
    cin>>ny;
    h = (b-a)/nx;
    k = (d-c)/ny;

    for (i=0; i<=nx; i++) {
        for (j=0; j<=ny; j++) 
            z[i][j] = f(a + i*h, c + j*k);
    }

    for (i=0; i<=nx; i++) {
        ax[i] = 0.0;
        for (j=0; j<=ny; j++) {
            if (j == 0 || j == ny)
                ax[i] += z[i][j];
            else if (j%2 == 1)
                ax[i] += 4.0*z[i][j];
            else
                ax[i] += 2.0*z[i][j];
        }
        ax[i] *= (k/3.0);
    }
    
    ans=0;

    for (i=0; i<=nx; i++) {
        if (i == 0 || i == nx)
            ans += ax[i];
        else if (i%2 == 1)
            ans += 4.0*ax[i];
        else
            ans += 2.0*ax[i];
    }
    ans *= (h/3.0);

    cout<<"\nThe value of the double integral with the given limits using Simpson's 1/3rd rule is "<<setprecision(4)<<fixed<<ans<<endl;

    return 0;
}