#include <stdio.h>
#include <stdlib.h>
int a[25][5];

//Assuming that in a subject only one student has highest marks

int main()
{
    int r,ch;
    printf("\nFAIZAN CHOUDHARY\n20BCS021\n\n");
    printf("Enter the number of students(max 25): ");
    scanf("%d", &r);
    for (int i=0; i<r; i++)
    {
        printf("Enter the roll number of student %d: ", i+1);
        scanf("%d", &a[i][0]);
        printf("Enter the age of student %d: ", i+1);
        scanf("%d", &a[i][1]);
        printf("Enter the marks in 3 subjects of student %d: ", i+1);
        for (int j=2; j<5; j++)
         scanf("%d", &a[i][j]);
    }

    printf("\nThe entries are as follows:\n");
    printf("\n\nRoll Number\t\tAge\t\tSubject_1\t\tSubject_2\t\tSubject_3\n");
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<5; j++)
         printf("%d\t\t\t", a[i][j]);
        printf("\n");
    }

    while (1)
    {
        float pr[r], mx=0;
        int index, roll1, roll2, flag=0;
        int max[3]={0,0,0}, rollno[3];
        printf("\n\nMENU\n1. Percentage secured by each student along with their roll numbers.\n2. Highest marks in each subject along with roll number\n3. Student scoring the highest percentage.\n4. Exit.\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: printf("\nRoll Number\t\tPercentage scored (%%)\n");
                    float per;
                    for (int i=0; i<r; i++)
                    {
                        per=0;
                        printf("%d\t\t\t", a[i][0]);                //printing roll no
                        for (int j=2; j<5; j++)                     //index starting from subject marks only
                        {
                            per+=a[i][j];
                        }
                        per/=3.0;
                        printf("%.2f\n", per);
                    }
                    break;

            case 2: for (int i=0; i<r; i++)
                    {
                        for (int j=2; j<5; j++)
                        {
                            if(a[i][j]>max[j-2])
                            {
                                max[j-2]=a[i][j];               //as according to the array given
                                rollno[j-2]=a[i][0];
                            }
                        }
                    }
                    printf("\nSubject\t\tHighest Marks\t\tRoll no who secured highest marks\n");
                    for (int j=0; j<3; j++)
                    {
                        printf("Subject_%d\t\t", j+1);
                        printf("%d\t\t", max[j]);
                        printf("%d\t\t\n", rollno[j]);
                    }
                    printf("\n");
                    break;

            case 3: 
                    for (int i=0; i<r; i++)             //finding percentage of each individual and storing them in pr[]
                    {
                        pr[i]=0;
                        for (int j=2; j<5; j++)
                        {
                            pr[i]+=a[i][j];
                        }
                        pr[i]/=3.0;
                        if (pr[i]>mx)                   //finding max percentage
                        {
                            mx=pr[i];
                            index=i;
                            roll1=a[i][0];
                        }
                    }
                    for (int i=0; i<r; i++)             //traversal
                    {
                        if (pr[i]==mx && i!=index)
                        {
                            if (a[i][1]<a[index][1])       //required age condition
                            {
                                roll1=a[i][0];
                                index=i;
                            }
                            else if (a[i][1]==a[index][1])
                            {
                                roll2=a[i][0];
                                flag=1;
                            }
                        }   
                    }
                    printf("\nStudent(s) who has/have scored the highest percentage are:\n");
                    if (flag==0)
                    {
                        printf("Roll No- %d", roll1);
                        printf(" with a percentage of %.2f\n", mx);
                    }
                    else if (flag==1)
                    {
                        printf("Roll No- %d", roll1);
                        printf(" with a percentage of %.2f\n", mx);
                        printf("Roll No- %d", roll2);
                        printf(" with a percentage of %.2f\n", mx);
                    }
                    break;
            case 4: exit(0);
        }
    }
    return 0;
}