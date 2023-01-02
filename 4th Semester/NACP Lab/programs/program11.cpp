#include <iostream>
using namespace std;
int *bin = new int[100];
int i = 0;

void decimal_to_binary (long long n) {
    while (n > 0) {
        bin[i++] = n%2;
        n = n/2;
    }
    for (int j=i-1; j>=0; j--)
        cout<<bin[j];
    cout<<endl;
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    long long N;
    cout<<"\nEnter decimal number: ";
    cin>>N;

    cout<<"\nThe binary representation of "<<N<<" is: ";
    decimal_to_binary(N);

    return 0;
} 