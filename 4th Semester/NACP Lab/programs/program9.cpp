#include <iostream>
using namespace std;

long GCD (int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (b > a)
        return GCD (b, a);
    else if (a == b)
        return a;
    else if (a > b)
        return GCD (b, a%b);
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    int a,b;
    cout<<"\nEnter the two integers: ";
    cin>>a>>b;

    long gcd = GCD(a,b);

    cout<<"\nThe GCD of "<<a<<" and "<<b<<" is: "<<gcd<<endl;

    return 0;
}