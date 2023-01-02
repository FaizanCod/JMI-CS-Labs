#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    double s, a, b, c, area;
    double *x = new double[3];
    double *y = new double[3];

    cout<<"\nEnter the three coordinates (x,y) of the triangle: ";
    for (int i=0; i<3; i++) {
        cout<<"\nEnter x"<<i+1<<": ";
        cin>>x[i];
        cout<<"Enter y"<<i+1<<": ";
        cin>>y[i];
    }

    cout<<"\nCoordinates:\n";
    for (int i=0; i<3; i++) {
        cout<<"("<<x[i]<<","<<y[i]<<")\n";
    }

    a = sqrt (pow (x[0]-x[1], 2) + pow (y[0]-y[1], 2));
    b = sqrt (pow (x[1]-x[2], 2) + pow (y[1]-y[2], 2));
    c = sqrt (pow (x[2]-x[0], 2) + pow (y[2]-y[0], 2));

    cout<<"\nSide lengths:\n";
    cout<<"a = "<<a<<"\nb = "<<b<<"\nc = "<<c<<"\n";

    s = (a+b+c)/2;
    area = sqrt (s*(s-a)*(s-b)*(s-c));
    cout.setf(ios::fixed);
    cout<<"\nThe area of the triangle is: "<<setprecision(4)<<area<<endl;

    return 0;
}