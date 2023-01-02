/*Program for Regula Falsi method*/
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double f (double x) {
    return x*log10(x) - 1.2;
}

int main() {
    double a, b, c, e;
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    cout<<"\nEnter initial approximation of the root: ";
    cin>>a>>b;
    cout<<"\nEnter the value of the tolerance: ";
    cin>>e;

    if (f(a) * f(b) >= 0) 
        cout<<"\nRoot is not lying between a and b\n";
    else {
        for(int i=1; i<=15; i++) {
            c = (a+b) / 2.0;
            if (f(c) == 0)
                break;
            else {
                if (abs(b - a) <= e)
                    break;
                if (f(a) * f(c) < 0)
                    b = c;
                else
                    a = c;
            }
            cout<<"\nIteration: "<<i<<"\tApproximation to the root is: "<<setprecision(4)<<fixed<<c<<endl;
        }
    }
    
    cout<<"\nTherefore the root of the given function is: "<<setprecision(4)<<fixed<<b<<endl;
    return 0;
}