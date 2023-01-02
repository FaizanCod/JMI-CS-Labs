/*Program for bisection method*/
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double func (double x) {         // Function definition 
    return cos(x) - x*exp(x);
}

int main() {
    double a, b, c, e;
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    cout<<"\nEnter initial approximations of the root: ";
    cin>>a>>b;
    cout<<"\nEnter the value of the tolerance: ";
    cin>>e;

    if (func(a) * func(b) >= 0)
        cout<<"\nRoot is not lying between a and b\n";
    else {
        for(int i=1; i<=15; i++) {
            c = (a+b) / 2.0;
            if (func(c) == 0)
                break;
            else {
                if (abs(b - a) <= e)
                    break;
                if (func(a) * func(c) < 0)
                    b = c;
                else
                    a = c;
            }
            cout<<"\nIteration: "<<i<<"\tApproximation to the root is: "<<setprecision(4)<<fixed<<c<<endl;
        }
    }
    cout<<"\nTherefore the root of the given function is: "<<setprecision(4)<<fixed<<c<<endl;
    return 0;
}
