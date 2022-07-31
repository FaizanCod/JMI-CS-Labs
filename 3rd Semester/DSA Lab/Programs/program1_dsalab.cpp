#include <iostream>
using namespace std;
int n;

void fact ()
{

    cout<<"\nEnter the number whose factorial is to be found: ";
    cin>>n;
    int temp=n;
    long long f=1;
    while (n>0)
    {
        f*=n;
        n--;
    }
    cout<<temp<<"! = "<<f<<endl;
}

void sum ()
{
    long sum=0;
    cout<<"\nEnter the number upto which sum is to be found (natural number): ";
    cin>>n;
    /*  OR
    sum=((n)*(n+1))/2;
    */
    if (n>0)
    {
        for (int i=0; i<=n; i++)
         sum+=i;
    }
    cout<<"\nSum of natural numbers upto "<<n<<" are: "<<sum;
}

void fibonacci ()
{
    int f=0, f1=1, f2=1, j=1;
    cout<<"\nEnter the limit upto which Fibonacci series is to be printed: ";
    cin>>n;
    cout<<"Fibonacci series: "<<endl;
    do
    {
        j++;
        cout<<f<<" ";
        f1=f2;
        f2=f;
        f=f1+f2;
    } while(j<=n);
}

void power()
{
    long a,b, res=1;
    cout<<"\nEnter the values of a and b: ";
    cin>>a>>b;
    int temp=b;
    while (b>0)
    {
        res*=a;
        b--;
    }
    cout<<"\n"<<a<<" ^ "<<temp<<" = "<<res;
}

int main()
{
    int ch;
    cout<<"FAIZAN CHOUDHARY\n20BCS021\n";
    while (1)
    {
        A:
        cout<<"\n\nMENU:\n1. Factorial of a given number. \n2. Sum of series of natural numbers. \n3. Fibonacci Series. \n4. Power of a raised to b.\n5. Exit. ";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch (ch)
        {
            case 1: fact();
                    break;
            case 2: sum();
                    break;
            case 3: fibonacci();
                    break;
            case 4: power();
                    break;
            case 5: exit(0);
            default: cout<<"\nWrong choice, enter again! ";
                     goto A;
        }
    }
    return 0;
}