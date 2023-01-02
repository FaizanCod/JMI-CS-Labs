#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double f (double a) {
    // integral of (2-2x+sin(x-1)+x^2)/(1+(x-1)^2)
    double ans;
    ans = (2 - 2*a + sin(a-1) + a*a) / (1 + (a-1)*(a-1));
    return ans;
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    int i, n;
    double x[15], y[15], k1, k2, k3, h, boole;

    x[0] = 0.5;
    n=12;
    x[n] = 1.7;
    k1 = k2 = k3 = 0.0;
    h = (x[n] - x[0]) / n;

    for (i=1; i<n; i++)
        x[i] = x[0] + i*h;

    for (i=0; i<=n; i++)
        y[i] = f(x[i]);

    for (i=1; i<n; i++) {
        if (i%4 == 0)
            k1 += 14 * y[i];
        else {
            if (i%2 == 0)
                k2 += 12 * y[i];
            else
                k3 += 32 * y[i];
        }
    }

    cout<<"\nThe values of x are: ";
    for (i=0; i<=n; i++)
        cout<<setprecision(4)<<fixed<<x[i]<<" ";

    cout<<"\nThe values of y are: ";
    for (i=0; i<=n; i++)
        cout<<setprecision(4)<<fixed<<y[i]<<" ";
    cout<<endl;

    boole = ((2*h) / 45) * (7*y[0] + 7*y[n] + k1 + k2 + k3);
    cout<<"\nThe value of the integral using Boole's rule: "<<setprecision(4)<<fixed<<boole<<endl;

    return 0;
}