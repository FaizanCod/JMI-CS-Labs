#include <iostream>
#include <math.h>
using namespace std;

int isPrime (int n) {
    int prime = 1;
    int j;
    for (j=2; j<=sqrt(n); j++) {
        if (n%j==0) {
            prime = 0;
            break;
        }
    }
    return prime;
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    int counter=0;
    cout<<"\nFirst 50 prime numbers generated not divisible by 5 and 7 are:\n";

    for (int i=2; counter<51; i++) {
        if (isPrime(i)) {
            if (i%5 !=0 && i%7 !=0) {
                if (counter == 30)
                    cout<<endl;
                cout<<i<<" ";
            }
                
            counter++;
        }
    }
    return 0;
}