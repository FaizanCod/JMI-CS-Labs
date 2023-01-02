//program to find binomial coeff nCr using fxn
#include <iostream>
using namespace std;

long int fact (long int n) {
    long int fac=1;
    while (n > 0) {
        fac*=n;
        n--;
    }
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n"; 
    long int n, r, coeff;
    cout<<"Enter the values of n and r for finding nCr: ";
    cin>>n>>r;
    if (n < r || n < 0 || r < 0) {
        cout<<"Invalid input";
        return 0;
    }
    else if (n == r)
        coeff = 1;
    else
        coeff= fact(n) / (fact(n-r) * fact(r));
    cout<<"\nnCr= "<<coeff;
    return 0;
}