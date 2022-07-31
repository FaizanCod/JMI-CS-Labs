#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[50];
    int roll;
    float sub[3];
    float per;
};

int check_roll (char *f_name, int r)
{
    struct Student t;
    int f=1;
    FILE *fp;
    fp = fopen (f_name, "r");
    if (fp == NULL)
    {
        printf("\nCannot open file!\n");
        return -1;
    }
    while (fread (&t, sizeof(struct Student), 1, fp))
    {
        if (t.roll == r)
        {
            printf("\nRoll Number already exists! Try again...\n");
            f=0;
        }
    }
    return f;
}

void insert_data (char *f_name)
{
    struct Student s;
    printf("\nEnter the name of the student: ");
    getchar();
    scanf("%[^\n]", s.name);
    B:
    printf("\nEnter the roll number of the student: ");
    scanf("%d", &s.roll);
    int k = check_roll(f_name,s.roll);
    if (!k)
        goto B;
    printf("\nEnter the marks of the student in three subjects: ");
    for (int i=0; i<3; i++)
        scanf("%f", &s.sub[i]);
    s.per = (s.sub[0] + s.sub[1] + s.sub[2]) / 3.0;

    FILE *fp;
    fp = fopen (f_name, "a");
    if (fp == NULL)
    {
        printf("\nCannot open file!\n");
        return;
    }
    fseek (fp, 0, SEEK_END);
    fwrite (&s, sizeof(struct Student), 1, fp);
    if(fwrite != 0)
        printf("\nInserted row successfully!\n");
    else
        printf("Error writing file!\n");
    fclose(fp);
}

void delete_data (char *f_name, int roll)
{
    FILE *fp, *fp_tmp;
    struct Student record;
    // flag for checking if record present or not
    int f=0;
    fp = fopen (f_name, "r");
    if (fp == NULL)
    {
        printf("\nCannot open file!\n");
        return;
    }
    // temp file to copy the rest of the records
    fp_tmp = fopen ("temp.txt", "w");
    if (fp_tmp == NULL)
    {
        printf("\nCannot open temporary file!\n");
        return;
    }
    while (fread (&record, sizeof(struct Student), 1, fp))
    {
        if (record.roll == roll)
        {
            printf("\nRecord with the given roll number found, and deleted successfully!\n");
            f=1;
        }
        else
            fwrite (&record, sizeof(struct Student), 1, fp_tmp);
    }
    if (!f)
    {
        printf("\nNo record found with the given roll number!\n");
        return;
    }
        
    fclose(fp);
    fclose(fp_tmp);

    remove(f_name);
    rename("temp.txt", f_name);
}

void update_data (char *f_name, int roll)
{
    FILE *fp, *fp_tmp;
    struct Student temp, record;

    printf("\nEnter new data:\n");
    printf("Name: ");
    getchar();
    scanf("%[^\n]", temp.name);
    printf("\nRoll number: ");
    scanf("%d", &temp.roll);
    printf("\nMarks in three subjects: ");
    for (int i=0; i<3; i++)
        scanf("%f", &temp.sub[i]);
    temp.per = (temp.sub[0] + temp.sub[1] + temp.sub[2]) / 3.0;

    // flag for checking if record present or not
    int f=0;
    fp = fopen (f_name, "r");
    if (fp == NULL)
    {
        printf("\nCannot open file!\n");
        return;
    }
    // temp file to copy the rest of the records
    fp_tmp = fopen ("temp.txt", "w");
    if (fp_tmp == NULL)
    {
        printf("\nCannot open temporary file!\n");
        return;
    }
    while (fread (&record, sizeof(struct Student), 1, fp))
    {
        if (record.roll == roll)
        {
            fwrite (&temp, sizeof(struct Student), 1, fp_tmp);
            printf("\nSuccessfully updated record!\n");
            f=1;
        }
        else
            fwrite (&record, sizeof(struct Student), 1, fp_tmp);  
    }
    
    if(!f)
    {
        printf("\nNo record found with the given roll number!\n");
        return;
    }

    fclose(fp);
    fclose(fp_tmp);

    remove(f_name);
    rename("temp.txt", f_name);
}

void display (char *f_name)
{
    FILE *fp = fopen (f_name, "r");
    if (fp == NULL)
    {
        printf("\nCannot open file!\n");
        return;
    }
    struct Student disp;
    printf("\n----------Student Details----------\n");
    printf("\nName\t\t\tRoll no\t\tSub 1\t\tSub 2\t\tSub 3\t\tPercentage");
    while (fread (&disp, sizeof(struct Student), 1, fp))
    {
        printf("\n%s\t%d\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f %%", disp.name, disp.roll, disp.sub[0], disp.sub[1], disp.sub[2], disp.per);
    }
    printf("\n\n----------------------------------\n");
    fclose(fp);
}

int main()
{
    printf("\nFAIZAN CHOUDHARY\n20BCS021\n\n");

    int n,ch,r;
    char *f = "student.txt";
    while (1)
    {
        A:
        printf("\nMENU\n1. Insert row.\n2. Delete row.\n3. Update row.\n4. Display.\n5. Exit.\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: insert_data(f);
                    break;

            case 2: printf("\nEnter the roll number whose record is to be deleted: ");
                    scanf("%d", &r);
                    delete_data(f,r);
                    break;

            case 3: printf("\nEnter the roll number whose record is to be updated: ");
                    scanf("%d", &r);
                    update_data(f,r);
                    break;

            case 4: display(f);
                    break;
            case 5: exit(0);
            default: printf("\nWrong choice! Enter again...\n");
                     goto A;
                     break;
        }
    }
    return 0;
}