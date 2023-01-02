#include <iostream>
using namespace std;

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    int i, j, n;
    double nr, dr, x, y=0.0, ax[15], ay[15];

    cout<<"\nEnter the number of points: ";
    cin>>n;

    cout<<"\nEnter the values of x: ";
    for(i=0;i<n;i++)
        cin>>ax[i];

    cout<<"\nEnter corresponding values of y: ";
    for(i=0;i<n;i++)
        cin>>ay[i];

    cout<<"\nEnter the value of x: ";
    cin>>x;

    for(i=0; i<n ;i++) {
        nr = dr = 1;
        for(j=0; j<n ;j++) {
            if(j != i) {
                nr *= (x - ax[j]);
                dr *= (ax[i] - ax[j]);
            }
        }
        y += (nr/dr)*ay[i];
    }
    cout<<"\nThe value of y("<<x<<") is: "<<y<<endl;

    return 0;
}