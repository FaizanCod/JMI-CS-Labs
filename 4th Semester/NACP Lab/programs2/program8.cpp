#include<iostream>
#include<iomanip>
using namespace std;

void display (double **a, int n) {
    int i, j;
    for (i=1; i<=n; i++) {
	    for (j=1; j<=(n+1); j++)
	        cout<<setprecision(2)<<fixed<<a[i][j]<<"\t";
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
	    for (k=i+1; k<=n; k++) {
		    double t = a[k][i] / a[i][i];
		    for (j=1; j<=n+1; j++)
		        a[k][j] -= t * a[i][j];
	    }
    }
    x[n] = a[n][n+1] / a[n][n];

    cout<<"\n\nThe matrix after Gauss-elimination is as follows:\n";
    display(a,n);

    for (i=n-1; i>=1; i--) {
        sum = 0.0;
	    x[i] = a[i][n];
	    for (j=i+1; j<=n; j++) 
	        sum += a[i][j] * x[j];
        x[i] = (a[i][n+1] - sum) / a[i][i];
    }

    cout<<"\nThe values of the variables are as follows:\n";
    for (i=1; i<=n; i++)
	    cout<<setprecision(4)<<fixed<<"\nx"<<i<<" = "<<x[i];
    cout<<endl;
    return 0;
}