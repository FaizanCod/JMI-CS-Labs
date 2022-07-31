#include <stdio.h>
#include <stdlib.h>

void display(int a[50][50], int r, int c)                         //to display resultant array
{
    printf("\nResultant array is:\n");
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            printf("%d", a[i][j]);
            printf("  ");
        }
        printf("\n");
    }
}

void add (int a[50][50],int r1, int c1, int b[50][50], int r2, int c2)          //addition function
{
    int c[50][50];
    if (r1==r2 && c1==c2)                                                           //checking for condition
    {
        for (int i=0; i<r1; i++)
        {
            for (int j=0; j<c1; j++)
            {
                c[i][j]=a[i][j]+b[i][j];
            }
        }
        display (c, r1, c2);
    }
    else
    {
        printf("\nThe matrices cannot be added!");
    }
}

void subtract (int a[50][50],int r1, int c1, int b[50][50], int r2, int c2)                 //subtraction function
{
    int c[50][50];                                                                            //checking for condition
    if (r1==r2 && c1==c2)
    {
        for (int i=0; i<r1; i++)
        {
            for (int j=0; j<c1; j++)
            {
                c[i][j]=a[i][j]-b[i][j];
            }
        }
        display (c, r1, c2);
    }
    else
    {
        printf("\nThe matrices cannot be subtracted!");
    }
}

void multiply (int a[50][50],int r1, int c1, int b[50][50], int r2, int c2)                 //multiplication function
{
    int c[50][50];
    if (c1==r2)                                                                                 //checking for condition
    {
        for (int i=0; i<r1; i++)
        {
            for (int j=0; j<c2; j++)
            {
                c[i][j]=0;
                for (int k=0; k<r2; k++)
                    c[i][j]+=a[i][k]*b[k][j];
            }
        }
        display (c, r1, c2);
    }
    else
    {
        printf("The matrices cannot be multiplied! ");
    }
}

int main()
{
    while (1)
    {
        int r1,c1,r2,c2, a[50][50], b[50][50];
        printf("\nEnter the no. of rows and columns for matrix 1: ");
        scanf("%d%d", &r1, &c1);
        printf("Enter the no. of rows and columns for matrix 2: ");
        scanf("%d%d", &r2, &c2);
        printf("Enter the matrix 1(row wise):\n");
        for (int i=0; i<r1; i++)
        {
            for (int j=0; j<c1; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        printf("Enter the matrix 2(row wise):\n");
        for (int i=0; i<r2; i++)
        {
            for (int j=0; j<c2; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }

        A:
        printf("\nMENU: \n1. Addition of two given matrices. \n2. Subtraction of two given matrices. \n3. Multiplication of two given matrices. \n4. Exit.");
        printf("\nEnter your choice: ");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: printf("Matrix 1: \n");
                    for (int i=0; i<r1; i++)
                    {
                        for (int j=0; j<c1; j++)
                        {
                            printf("%d", a[i][j]);
                            printf("  ");
                        }
                        printf("\n");
                    }
                    printf("\nMatrix 2: \n");
                    for (int i=0; i<r2; i++)
                    {
                        for (int j=0; j<c2; j++)
                        {
                            printf("%d", b[i][j]);
                            printf("  ");
                        }
                        printf("\n");
                    }
                    add (a, r1, c1, b, r2, c2);
                    break;
            case 2: printf("Matrix 1: \n");
                    for (int i=0; i<r1; i++)
                    {
                        for (int j=0; j<c1; j++)
                        {
                            printf("%d", a[i][j]);
                            printf("  ");
                        }
                        printf("\n");
                    }
                    printf("\nMatrix 2: \n");
                    for (int i=0; i<r2; i++)
                    {
                        for (int j=0; j<c2; j++)
                        {
                            printf("%d", b[i][j]);
                            printf("  ");
                        }
                        printf("\n");
                    }
                    subtract (a, r1, c1, b, r2, c2);
                    break;
            case 3: printf("Matrix 1: \n");
                    for (int i=0; i<r1; i++)
                    {
                        for (int j=0; j<c1; j++)
                        {
                            printf("%d", a[i][j]);
                            printf("  ");
                        }
                        printf("\n");
                    }
                    printf("\nMatrix 2: \n");
                    for (int i=0; i<r2; i++)
                    {
                        for (int j=0; j<c2; j++)
                        {
                            printf("%d", b[i][j]);
                            printf("  ");
                        }
                        printf("\n");
                    }
                    multiply (a, r1, c1, b, r2, c2);
                    break;
            case 4: exit(0);
            default: printf("Wrong choice entered! Try again! ");
                     goto A;
        }
    }
    return 0;
}