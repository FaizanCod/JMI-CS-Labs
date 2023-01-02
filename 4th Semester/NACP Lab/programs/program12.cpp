#include <iostream>
#include <math.h>
using namespace std;

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    long long N, temp;

    cout<<"\nEnter binary number: ";
    cin>>N;
    temp = N;

    long long decimal = 0;
    int i = 0;
    while (N > 0) {
        decimal += N%10 * pow(2, i);
        N = N/10;
        i++;
    }

    cout<<"\nThe decimal representation of "<<temp<<" is: "<<decimal<<endl;

    return 0;
}