#include <iostream>
using namespace std;

int GCD (int a, int b) {
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
    int a, b, c, d;
    cout<<"\nEnter the four numbers: ";
    cin>>a>>b>>c>>d;

    int gcd = GCD ( GCD (a, b), GCD (c, d) );
    cout<<"\nThe GCD of the four numbers is: "<<gcd;
    
    int lcm = a * b * c * d / GCD ( GCD (a*b*c, a*b*d), GCD (a*c*d, b*c*d) );
    cout<<"\nThe LCM of the four numbers is: "<<lcm;

    int max = a > b ? a > c ? a > d ? a : b : c : d;
    cout<<"\nThe maximum of the four numbers is: "<<max;

    int min = a < b ? a < c ? a < d ? a : b : c : d;
    cout<<"\nThe minimum of the four numbers is: "<<min;
    
    return 0;
}