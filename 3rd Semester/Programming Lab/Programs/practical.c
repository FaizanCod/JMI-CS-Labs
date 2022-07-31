// WAP to calculate the difference in number of days between two dates.
// (Dates are entered as a single string). For eg. “08-11-2021,15-01-1932”

#include <stdio.h>

// 08-11-2021,09-05-1972    18080 days
// 06-01-2016,28-02-2020    1514 days
// 12-01-1880,14-10-2021    51775 days
// 08-01-2017,08-01-2021    1461 days

// function to check if an entered year is leap year or not
int isLeap(int y)
{
    // leap year check: if year is divisible by 4 and it is not divisible by 100, or if it is divisible by 400, it is a leap year
    if ((y%4==0 && y%100!=0) || (y%400==0))
        return 1;
    return 0;
}

// function to check and add leap days from y1 to y2
long leapYear(int y1, int y2)
{
    long j, s=0;
    for (j=y1; j<y2; j++)
    {
        // adding days between the two years
        s+=365;
        if (isLeap(j)==1)
        // for 366 days
            s++;
    }
    return s;
}

long daysofyear (int d, int m, int y)
{
    long res, day[13];
    // initialising each month with the sum of its previous months
    day[1] = 0; day[2] = 31; day[3] = 59; day[4] = 90;
    day[5] = 120; day[6] = 151; day[7] = 181; day[8] = 212;
    day[9] = 243; day[10]= 273; day[11]= 304; day[12]= 334;
    res = day[m]+d;
    // since if the month is Jan or Feb, we won't include the leap day
    if(isLeap(y) == 1 && (m>2))
        res++;
    return res;
}

long daysdiff (int d1, int m1, int y1, int d2, int m2, int y2)
{
    long days;
    // finding out difference in days and months
    days = daysofyear(d2, m2, y2) - daysofyear(d1, m1, y1);
    if (y1!=y2)
    {
        // adding the days of year
        if (y1<y2)
            days+=leapYear(y1,y2);
        else
            days-=leapYear(y2,y1);
    }
    return (days>0) ? days : -days;  
}

int valid(int d, int m, int y)
{
    int is_valid = 1;
    if (m >= 1 && m <= 12)
    {
        // February
        if (m == 2)
        {
            if (isLeap(y) && d == 29)
                is_valid = 1;
            // if not leap year, February can have atmost 28 days
            else if (d > 28)
                is_valid = 0;
        }
        // April, June, September, November = 30 days
        else if (m == 4 || m == 6 || m == 9 || m == 11)
        {
            if (d > 30)
                is_valid = 0;
        }
        
        else if (d > 31)
            is_valid = 0;
    }
    // for value of m to lie between 1-12
    else
        is_valid = 0;

    return is_valid;
}

int main()
{
    char date[25], date1[11], date2[11], ch='y';
    int i;
    int d1=0, m1=0, y1=0, d2=0, m2=0, y2=0;
    int flag = 0;
    printf("\nFAIZAN CHOUDHARY\n20BCS021\n\n");

    do
    {
        A:
        printf("\nEnter the string containing two dates (separated by comma) (EX: 06-01-2016,28-02-2020): ");
        scanf("%s", &date);
        
        // splitting the date string into two strings
        for (i=0; date[i]!=','; i++)
        {
            date1[i] = date[i];
            date2[i] = date[i+11];
        }

        // to convert char into number by subtracting from reference '0' (ASCII - 48)
        d1 = (date1[0]-'0')*10 + date1[1]-'0';
        d2 = (date2[0]-'0')*10 + date2[1]-'0';

        m1 = (date1[3]-'0')*10 + date1[4]-'0';
        m2 = (date2[3]-'0')*10 + date2[4]-'0';

        y1 = (date1[6]-'0')*1000 + (date1[7]-'0')*100 + (date1[8]-'0')*10 + date1[9]-'0';
        y2 = (date2[6]-'0')*1000 + (date2[7]-'0')*100 + (date2[8]-'0')*10 + date2[9]-'0';

        if (!valid(d1,m1,y1))
        {
            flag = 1;
            printf("\nFirst date is invalid.\n");
        }

        if (!valid(d2,m2,y2))
        {
            flag = 1;
            printf("\nSecond date is invalid.\n");
        }

        if (flag) {
            flag = 0;
            goto A;
        }

        long res = daysdiff(d1, m1, y1, d2, m2, y2);
        printf("\nNo of Days: %ld", res);
    
        printf("\nDo you want to enter more? (y/n) ");
        getchar();
        scanf("%c", &ch);

    } while(ch=='y'||ch=='Y');
    
    return 0;
}