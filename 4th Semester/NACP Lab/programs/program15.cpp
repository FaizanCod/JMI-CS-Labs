#include <iostream>
#include <math.h>
using namespace std;

float fact (float n) {
    long int fac=1;
    while (n > 0) {
        fac*=n;
        n--;
    }
    return fac;
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    double x = 0.123;
    double t, sum, i;

    // first term
    sum = 1;
    // variables to store sum of odd and even terms
    double sum_odd = 0, sum_even = 0;

    for (i=1; i<=3; i++) {
        sum_even += pow(x, 2*i-1) / (2*i-1);
        sum_odd += (2 * i) * pow (x, 2*i) / fact(4*i);
    }

    sum += sum_even + sum_odd;

    cout<<"\nThe sum of the series at x = 0.123 is: "<<sum<<endl;

    return 0;
}