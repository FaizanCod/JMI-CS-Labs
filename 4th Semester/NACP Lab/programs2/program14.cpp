/*Program for Newton Raphson method*/
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double f (double x) {
    return cos(x) - x*exp(x);
}

double df (double x) {        // Derivative of Function
    return -sin(x) - exp(x) - x*exp(x);
}

int main() {
    double a, b, e;
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    cout<<"\nEnter initial approximation of the root: ";
    cin>>a;
    cout<<"\nEnter the value of the tolerance: ";
    cin>>e;

    for (int i=1; i<=15; i++) {
        b = a - (f(a) / df(a));
        if (f(b) == 0) {
            cout<<"\nActual root is: "<<b;
            break;
        }
        else {
            if (abs(b - a) <= e)
                break;
            else
                a = b;
            cout<<"\nIteration: "<<i<<"\tApproximation to the root is: "<<setprecision(4)<<fixed<<b<<endl;
        }
    }
    cout<<"\nTherefore the root of the given function is: "<<setprecision(4)<<fixed<<b<<endl;
    return 0;
}