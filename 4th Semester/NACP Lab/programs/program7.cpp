#include <iostream>
using namespace std;

bool isRev (long long n) {
    long long sq = n*n;
    int digit=0;
    long long rev=0, rev_sq=0;
    while(n > 0) {
        digit = n%10;
        rev = rev*10 + digit;
        n/=10;
    }
    while (sq > 0) {
        digit = sq%10;
        rev_sq = rev_sq*10 + digit;
        sq/=10;
    }
    
    if (rev * rev == rev_sq)
        return true;
    return false;
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    long long N;
    cout<<"\nEnter the limit upto which such numbers are to be found: ";
    cin>>N;

    long long i;
    // since for 1 2 3 squares are single digits
    cout<<"\nNumbers matching the given condition are:\n";
    for (i=4; i<=N; i++) {
        if (isRev(i))
            cout<<i<<" ";
    }
    return 0;
}