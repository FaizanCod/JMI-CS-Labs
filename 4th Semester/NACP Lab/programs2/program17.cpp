// to solve system of differential equations using Runge-Kutta method.
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double f1 (double x, double y, double z) {
    return (1 + x*z);
}

double f2 (double x, double y, double z) {
    return (-x*y);
}

int main () {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    double k1, k2, k3, k4, l1, l2, l3, l4;
    double x0, y0, z0, h, x, n;

    cout<<"\nEnter initial values of x, y, z: ";
    cin>>x0>>y0>>z0;
    cout<<"\nEnter the value of the step size: ";
    cin>>h;
    cout<<"\nEnter the value of x where the solution is to be found: ";
    cin>>x;
    n = (x - x0) / h;

    for (int i=1; i<=n; i++) {
        k1 = h * f1(x0, y0, z0);
        l1 = h * f2(x0, y0, z0);
        k2 = h * f1(x0 + 0.5 * h, y0 + 0.5 * k1, z0 + 0.5 * l1);
        l2 = h * f2(x0 + 0.5 * h, y0 + 0.5 * k1, z0 + 0.5 * l1);
        k3 = h * f1(x0 + 0.5 * h, y0 + 0.5 * k2, z0 + 0.5 * l2);
        l3 = h * f2(x0 + 0.5 * h, y0 + 0.5 * k2, z0 + 0.5 * l2);
        k4 = h * f1(x0 + h, y0 + k3, z0 + l3);
        l4 = h * f2(x0 + h, y0 + k3, z0 + l3);
        x0 = x0 + h;
        y0 = y0 + (1.0/6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        z0 = z0 + (1.0/6.0) * (l1 + 2 * l2 + 2 * l3 + l4);

        cout<<"\nAfter iteration "<<i<<" the values of x, y, z are: "<<setprecision(4)<<fixed<<x0<<" "<<y0<<" "<<z0<<endl;
    }
    return 0;
}