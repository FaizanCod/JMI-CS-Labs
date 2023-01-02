#include <iostream>
using namespace std;

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    int n;

    cout<<"\nEnter the number of points: ";
    cin>>n;

    float *x = new float[n];
    float *y = new float[n];

    float sum_x = 0, sum_y = 0;
    float sum_x_sq = 0, sum_xy = 0;

    float m, c;

    cout<<"\nEnter the points";
    for (int i=0; i<n; i++) {
        cout<<"\nEnter x"<<i+1<<": ";
        cin>>x[i];
        cout<<"Enter y"<<i+1<<": ";
        cin>>y[i];
        sum_x += x[i];
        sum_y += y[i];
        sum_x_sq += x[i]*x[i];
        sum_xy += x[i]*y[i];
    }

    m = ((n*sum_xy) - (sum_x*sum_y)) / ((n*sum_x_sq) - (sum_x*sum_x));
    c = (sum_y - m*sum_x)/n;

    cout<<"\nThe equation of the line of best fit is y = "<<m<<"x + "<<c<<endl;
    
    return 0;
}