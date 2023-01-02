//Program for Gauss Seidal method
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

#define f1(w, x, y, z) (18 - 2*x - y - z) / 10.0
#define f2(w, x, y, z) (15 - 2*w - y - z) / 10.0
#define f3(w, x, y, z) (27 - w - x - 2*z) / 10.0
#define f4(w, x, y, z) (-9 - w - x - 2*y) / 10.0

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    double w0=0.0, x0=0.0, y0=0.0, z0=0.0, w1, x1, y1, z1, e1, e2, e3, e4, e;
    int n = 4, count = 1;

    cout<<"\nEnter the tolerable error: ";
    cin>>e;

    cout<<"\nIteration\tx\ty\tz\n";
    cout<<"----------------------------------------------------\n";
    
    do {
        w1 = f1 (w0, x0, y0, z0);
        x1 = f2 (w1, x0, y0, z0);
        y1 = f3 (w1, x1, y0, z0);
        z1 = f4 (w1, x1, y1, z0);

        cout<<setprecision(4)<<fixed<<count<<"\t\t"<<x1<<"\t"<<y1<<"\t"<<z1<<"\n";

        e1 = fabs(w1 - w0);
        e2 = fabs(x1 - x0);
        e3 = fabs(y1 - y0);
        e4 = fabs(z1 - z0);

        count++;

        w0 = w1;
        x0 = x1;
        y0 = y1;
        z0 = z1;
    } while (e1 > e && e2 > e && e3 > e && e4 > e);

    cout<<"\nThe solution is:\n";
    cout<<"\nw = "<<w1<<"\nx = "<<x1<<"\ny = "<<y1<<"\nz = "<<z1<<"\n";

    return 0;
}