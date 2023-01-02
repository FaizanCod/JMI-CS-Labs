#include <iostream>
using namespace std;

void sum_cubes(int n) {
    long long sum = 0;
    for (int i=1; i<=n; i++) {
        sum += i*i*i;
        if (i < 3)
            cout<<"\n"<<i<<"^3 = "<<i*i*i<<"\t\tSum = "<<sum;
        else
            cout<<"\n"<<i<<"^3 = "<<i*i*i<<"\tSum = "<<sum;
    }
    cout<<"\nSum of cubes of first "<<n<<" natural numbers is "<<sum;
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    sum_cubes(10);

    return 0;
}