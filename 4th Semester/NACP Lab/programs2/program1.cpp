#include <iostream>
using namespace std;

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    
    int n,i, j=1;
    double f, f1=1, f2=0, k;
    cout<<"\nEnter the number of observations: ";
    cin>>n;

    int *x = new int[n+1];
    int *y = new int[n+1];
    int *p = new int[n+1];

    cout<<"\nEnter the values of x: ";
    for(i=1;i<=n;i++)
        cin>>x[i];

    cout<<"\nEnter corresponding values of y: ";
    for(i=1;i<=n;i++)
        cin>>y[i];

    f = y[1];
    cout<<"\nEnter the value of k for which f(k) is to be calculated: ";
    cin>>k;

    do {
        for (i=1; i<=n-1; i++) {
            p[i] = ((y[i+1]-y[i])/(x[i+j]-x[i]));
            y[i] = p[i];
        }
        f1 = 1;

        for (i=1; i<=j; i++)
            f1 *= (k - x[i]);

        f2 += (y[1] * f1);
        j++;
        n--;
    } while (n != 1);

    f += f2;
    cout<<"\nThe value of f("<<k<<") is: "<<f<<endl;

    return 0;
}