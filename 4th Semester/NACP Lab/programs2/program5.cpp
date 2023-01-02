// Weddle's Rule for the evaluation of Definite Integrals
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double f (double x) {
    double a = sin(x) - log(x) + exp(x);
    return a;
}

int main() {
    int n, i;
    double a, b, h, integral =0;
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";  
    cout<<"\nEnter the limits of integration\nInitial limit a = ";    //get the limits of integration
    cin>>a;
    cout<<"Final limit b = ";
    cin>>b;
    cout<<"Number of subintervals n = ";
    cin>>n; 
  
    if (n%6 != 0)
        cout<<"\nNumber of subintervals should be a multiple of 6 for Weddle's Rule to be applicable\n";        
    else {
        int m = n/6; 
	    double x[n+1],y[n+1];    
        h = (b-a)/n;                                          // get the width of the subintervals
        for (i=0; i<=n; i++) {                                // loop to evaluate x0,...xn and y0,...yn
            x[i] = a + i*h;      
            y[i] = f(x[i]);
        }
        for (i=1; i<=m; i++) {                                // loop to evaluate the sum
	        integral += (3.0*h/10.0) * (f(a) + f(a + 2*h) + 5*f(a+h) + 6*f(a + 3*h) + f(a + 4*h) + 5*f(a + 5*h)+ f(a + 6*h));
            a += 6*h;
        }

        cout<<"\nThe values of x are: ";
        for (i=0; i<=n; i++)
            cout<<setprecision(4)<<fixed<<x[i]<<" ";
        cout<<"\nThe values of y are: ";
        for (i=0; i<=n; i++)
            cout<<setprecision(4)<<fixed<<y[i]<<" ";
        cout<<endl;

        // integral = (3.0*h/10.0) * (sum + y[0] + y[n]);
        cout<<"\nThe value of integral using Weddle's Rule is "<<setprecision(4)<<fixed<<integral<<endl;        
    }
    return 0;
}