#include <iostream>
#include <math.h>
using namespace std;

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    int n, k;
    float sum_x = 0, sum_sq_x = 0;
    float mean, std_dev, var;

    cout<<"\nEnter the number of values: ";
    cin>>n;

    cout<<"\nEnter the values: ";
    for (int i=0; i<n; i++) {
        cin>>k;
        sum_x += k;
        sum_sq_x += k*k;
    }
    mean = sum_x/n;
    var = sum_sq_x/n - mean*mean;
    std_dev = sqrt(var);

    cout<<"\nThe mean is: "<<mean;
    cout<<"\nVariance is: "<<var;
    cout<<"\nThe standard deviation is: "<<std_dev;

    return 0;
}