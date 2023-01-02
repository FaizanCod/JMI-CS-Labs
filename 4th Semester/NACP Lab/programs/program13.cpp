#include <iostream>
#include <math.h>
#include <iomanip>
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
    float x, t, sum=0, i;
    // 15 is the number of terms
    int n=15;
    cout.setf (ios::fixed);
    x = 0.12;
    // adding first term
    sum += x;
    t = x;
    for (i=1; i<=n; ++i) {
        t = ((pow(-1,i) * pow(x,(2*i+1))) / (fact(2*i)) );
        sum += t;
    }
    cout<<"Sum of first 15 terms of sine series with x = 0.12: \nsin(x) = "<<setprecision(4)<<sum<<endl;
    return 0;
}