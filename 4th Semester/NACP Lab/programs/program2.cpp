#include <iostream>
using namespace std;
long long *fib;

long long fibonacci (int n) {
    if (n<0)
        return 0;
    if (n==0 || n==1){
        fib[n] = n;
        return n;
    }
    else {
        if (fib[n-2]==-1)
            fib[n-2] = fibonacci(n-2);
        if (fib[n-1]==-1)
            fib[n-1] = fibonacci(n-1);
        fib[n] = fib[n-2] + fib[n-1];
        return fib[n];
    }
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n"; 
    int n;
    cout<<"\nEnter the number of terms: ";
    cin>>n;
    fib = new long long[n+1];
    for (int i=0; i<=n; i++)
        fib[i] = -1;
    fibonacci(n);
    cout<<"\nFibonacci series using recursion: ";
    for (int i=0; i<=n; i++)
        cout<<fib[i]<<" ";
    return 0;
}  