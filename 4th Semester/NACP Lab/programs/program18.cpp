#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

void print_cos() {
    float x;
    for (x=0; x<=180; x+=30) {
        float f = (x * 3.14159) / 180;
        cout.setf(ios::fixed);
        cout<<"\nThe value of cos("<<x<<") is: "<<setprecision(4)<<cos(f)<<endl;
    }
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    print_cos();
    return 0;
}