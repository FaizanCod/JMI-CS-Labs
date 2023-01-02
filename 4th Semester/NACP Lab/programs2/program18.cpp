// Milne's Method
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double f (double a, double b) {
    double r = (a*a + 3*b*b) / 10;
    return r;
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    double x0, y0, h, xn, x[10], y[10];
    double f1, f2, f3, f4, f5, k1, k2, k3, k4, yi, yc;
    int i, n;

    cout<<"\nEnter the initial values of x, y: ";
    cin>>x0>>y0;
    cout<<"\nEnter the value of the step size: ";
    cin>>h;
    cout<<"\nEnter the final value of x: ";
    cin>>xn;
    n = (xn - x0) / h;
    x[0] = x0;
    y[0] = y0;

    for (i=1; i<=n; i++)
        x[i] = x[0] + i*h;

    for (i=1; i<=n; i++) {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + 0.5 * h, y0 + 0.5 * k1);
        k3 = h * f(x0 + 0.5 * h, y0 + 0.5 * k2);
        k4 = h * f(x0 + h, y0 + k3);
        y[i] = y[i-1] + (1.0/6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x0 = x0 + h;
        y0 = y[i];
    }

    cout<<"\nThe values of x and y are: "<<endl;
    cout<<"x\ty"<<endl;
    for (i=0; i<=n; i++)
        cout<<x[i]<<"\t"<<y[i]<<endl;

    f1 = f(x[1], y[1]);
    f2 = f(x[2], y[2]);
    f3 = f(x[3], y[3]);

    // Milne's Predictor
    y[4] = y[0] + (4*h/3.0) * (2*f1 - f2 + 2*f3);
    A:
    // cout<<"Hello";
    f4 = f(x[4], y[4]);

    cout<<"\nThe predicted value of y[4] is: "<<y[4]<<endl;
    // Milne's Corrector
    yi = y[2] + (h/3.0) * (f2 + 4*f3 + f4);

    if (fabs((yi - y[4]) / yi) <= 0.0001)
        goto B;
    else {
        y[4] = yi;
        goto A;
    } 

    B:
    y[5] = y[1] + (4*h/3.0) * (2*f2 - f3 + 2*f4);
    f5 = f(x[5], y[5]);
    yc = y[3] + (h/3.0) * (f3 + 2*f4 + f5);
    while (fabs((yc - y[5]) / yc) <= 0.0001) {
        y[5] = yc;
        f5 = f(x[5], y[5]);
        yc = y[3] + (h/3.0) * (f3 + 2*f4 + f5);
    }


    cout<<"\nThe corrected values of x, y are: "<<endl;
    cout<<"x\ty"<<endl;
    for (i=0; i<=n; i++)
        cout<<x[i]<<"\t"<<y[i]<<endl;
    
    return 0;
}