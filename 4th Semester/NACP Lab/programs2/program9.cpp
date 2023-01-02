#include<iostream>
#include<iomanip>
using namespace std;

void display (double **a, int n) {
    int i, j;
    for (i=1; i<=n; i++) {
	    for (j=1; j<=(n+1); j++)
	        cout<<setprecision(3)<<fixed<<a[i][j]<<"\t";
	    cout<<endl;
    }
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    int n, i, j, k;

    cout<<"\nEnter the no. of equations: ";
    cin>>n;
    double sum = 0.0;
    double **a = new double*[n+1];
    for (i=1; i<=n; i++)
        a[i] = new double[n+2];
    double *x = new double[n+1];

    cout<<"\nEnter the elements of the augmented-matrix row-wise:\n";
    for (i=1; i<=n ;i++) {
	    for (j=1; j<=(n+1) ;j++)
	        cin>>a[i][j];
    }

    cout<<"\nThe entered matrix is:\n";
    display(a,n);

    for (i=1; i<=n; i++) {
        if (a[i][i] == 0.0) {
            cout<<"Mathematical Error!";
            exit(0);
        }
	    for (j=1; j<=n; j++) {
            if (i != j) {
		    double t = a[j][i] / a[i][i];
		    for (k=1; k<=n+1; k++)
		        a[j][k] -= t * a[i][k];
            }
	    }
    }

    for (i=1; i<=n; i++)
        x[i] = a[i][n+1] / a[i][i];

    cout<<"\n\nThe matrix after Gauss Jordan is as follows:\n";
    display(a,n);

    cout<<"\nThe values of the variables are as follows:\n";
    for (i=1; i<=n; i++)
	    cout<<setprecision(4)<<fixed<<"\nx"<<i<<" = "<<x[i];
    cout<<endl;
    return 0;
}