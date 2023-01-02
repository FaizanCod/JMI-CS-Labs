//Simpson 1-3 Method for the evaluation of Definite Integrals
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double f (double x) {
    double a = exp(x * tan(x));
    return a;
}

int main() {
    int n, i;
    double a, b, h, sum = 0, integral;
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";  
    cout<<"\nEnter the limits of integration\nInitial limit a = ";    //get the limits of integration
    cin>>a;
    cout<<"Final limit b = ";
    cin>>b;
    cout<<"Enter the no. of subintervals n = ";              // get the no. of subintervals
    cin>>n;    
    if (n%2 != 0)
    cout<<"Number of subintervals should be even";
    else {
	    double x[n+1],y[n+1];    
        h = (b-a)/n;                                          // get the width of the subintervals
        for (i=0; i<=n; i++) {                                // loop to evaluate x0,...xn and y0,...yn
            x[i] = a + i*h;      
            y[i] = f(x[i]);
        }
        for (i=1; i<n; i++) {                                // loop to evaluate the sum
	        if (i%2 == 0)
                sum+=2.0*y[i];      
            else
                sum+=4.0*y[i];
        }

        cout<<"\nThe values of x are: ";
        for (i=0; i<=n; i++)
            cout<<setprecision(4)<<fixed<<x[i]<<" ";
        cout<<"\nThe values of y are: ";
        for (i=0; i<=n; i++)
            cout<<setprecision(4)<<fixed<<y[i]<<" ";
        cout<<endl;

        integral = (h/3.0) * (sum + y[0] + y[n]);
        cout<<"\nThe value of integral using Simpson's 1/3rd Rule is "<<setprecision(4)<<fixed<<integral<<endl;        
    }
    return 0;
}