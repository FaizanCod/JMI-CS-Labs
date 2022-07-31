#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char mainstr[100], str1[50], str2[50];
int ind, flag=0, j;

int index_of_substr(char mainstr[], char str1[])
{
    flag=0;
    for (int a=0; mainstr[a]!='\0'; a++)
    {
        for (int i=a; mainstr[i]!='\0'; i++)              //to take out smaller strings out of mainstr
        {
            if (mainstr[i]==str1[0])
            {
                ind=i;
                j=0;
                while (mainstr[i]==str1[j])               //to let the check go on until substr or mainstr ends, and ensuring that the substr is exactly in the mainstr
                {
                    i++;
                    j++;
                }
                if (j>=strlen(str1))                      //if the length in string to be checked is less than the checking condition
                {
                    flag=1;
                    break;
                }
            }
        }
        if (flag)
            return ind;
    }
    return -1;
}

void substr_before(char mainstr[], char strb[], int index)
{
    int c=index;
    int i=0;
    while (i!=c)
    {
        strb[i] = mainstr[i];
        i++;
    }
}

void substr_after(char mainstr[], char stra[], int index)
{
    int c=index;
    int i=0;

    for (i=index; mainstr[i]!=' '; i++)
        c++;
    i=0;
    while (mainstr[i+c]!='\0')
    {
        stra[i] = mainstr[i+c];
        i++;
    }
    // for last word
    if (stra[0]=='.' )
        stra[0]=' ';
        
}

void replace (char replace[], char strb[], char str2[], char stra[])
{
    int k=strlen(strb);
    int l=strlen(str2);
    int m=strlen(stra);
    for (int i=0; i<k; i++)
        replace[i]=strb[i];
    for (int i=0; i<l; i++)
        replace[k+i]=str2[i];
    for (int i=0; i<m; i++)
        replace[k+l+i]=stra[i];
    replace[k+l+m]='\0';
    printf("%s\n", replace);
}

int main()
{
    printf("\nFAIZAN CHOUDHARY\n20BCS021\n\n");

    int ch, count=0;
    while(1)
    {
        A:
        count++;
        printf("Enter the main string (ending with .): ");
        if (count>1)
        {
            getchar();
            scanf("%[^\n]", &mainstr);
        }
        else
            scanf("%[^\n]", &mainstr);
        B:
        // str1[50]={'\0'};
        printf("Enter the substring to be found (case sensitive): ");
        getchar(); 
        scanf("%[^\n]", &str1);

        if (index_of_substr(mainstr, str1)==-1)
        {
            printf("\nSubstring is not present in the main string!");
            C:
            printf("\nChoose: \n1. Start Over.\n2. Re-enter substring.\n3. Exit.\n");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1: goto A;
                    break;
            case 2: goto B;
                    break;
            case 3: exit(0);
            default: printf("\nWrong choice! Enter again...\n");
                     goto C;
            }
        }
        else
        {
            char stra[50]={'\0'};
            char strb[50]={'\0'};
            substr_before(mainstr, strb, ind);
            substr_after(mainstr, stra, ind);
            printf("\nSubstring is present in the main string at index %d!", ind);
            D:
            printf("\nEnter the string to replace: ");
            char str2[50]={'\0'};
            getchar();
            scanf("%[^\n]", &str2);
            printf("\nAfter replacement: ");
            replace(mainstr, strb, str2, stra);
            printf("\nChoose: \n1. Start Over.\n2. Continue with same string. \n3. Exit.\n");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1: goto A;
                    break;
            case 2: goto B;
            case 3: exit(0);
            default: printf("\nWrong choice! Enter again...\n");
                     goto D;
            }
        }
    }
    
    return 0;
}