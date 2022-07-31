#include <stdio.h>
#include <stdlib.h>

char string[100];  //temp string
// char *s=(char *)malloc(100*sizeof(char));  
char s[100];      //main string input
char b[100];      //secondary input

int strlen (char *s)
{
    int count=0;
    for (int i=0; s[i]!='\0'; i++)
     count++;
    return count;
}

char * strrev (char *s)
{
    int k=strlen(s);
    for (int i=0; s[i]!='\0'; i++)
     string[i]=s[k-1-i];
    return string;
}

char * strcpy (char *s,char *b)
{
    // int k = strlen (b);
    // char *s=(char *)realloc(s, (k+1) * sizeof(char));
    char *temp=s;
    while (*b!='\0')
    {
        *s=*b;
        s++;
        b++;
    }
    *s='\0';
    return temp;
}

void strcmp (char *a, char *b)
{
    while (*a)
    {
        if (*a!=*b)
        {
            printf("\nThe two strings are not equal!\n");
            return;
        }
        a++;
        b++;
    }
    printf("\nThe two strings are equal!\n");
}

char *strcat (char *a, char *b)
{
    int k=strlen(a);
    int l=strlen(b);
    for (int i=0; i<k; i++)
     string[i]=a[i];
    for (int i=0; i<l; i++)
     string[k+i]=b[i];
    string[strlen(string)]='\0';
    return string;
}

void palindrome (char *s)
{
    int len=strlen(s), j, flag=1;
    for (int i=0; i<len-1, j<len/2; i++, j--)
    {
        if (s[i]!=s[j])
        { 
            flag=0;
            break;
        }  
    }
    if (!flag)
     printf("\nThe given string is not a palindrome.\n");
    else 
     printf("\nThe given string is a palindrome.\n");
}

int substr(char *a, char *b)
{
    int k=strlen(a);    //substring
    int l=strlen(b);    //main string
    for (int i=0; i<=(l-k); i++)        //to traverse in larger string upto the length of smaller string
    {
        int j;
        for (j=0; j<k; j++)
         if (b[i+j] != a[j])
          break;
        if (j==k)
         return i;
    }
    return -1;
}

int main()
{
    int ch;
    printf("\nFAIZAN CHOUDHARY\n20BCS021\n\n");
    A:
    printf("Enter the main string: ");
    scanf("%[^\n]", &s);
    while (1)
    {
        B:
        printf("\n\nMENU\n1. strlen\n2. strrev\n3. strcpy\n4. strcmp\n5. strcat\n6. Check for palindrome.\n7. Search for substring.\n8. Enter new main string.\n9. Exit.\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nLength of the string is: %d\n", strlen(s));
                    break;
            case 2: printf("\nString after reversing: %s\n", strrev(s));
                    break;
            case 3: printf("\nEnter the string to be copied: ");
                    getchar();
                    scanf("%[^\n]", &b);
                    printf("\nMain String: %s\nSecondary String: %s", s,b);
                    printf("\nAfter Copying, Main String: %s\n",strcpy(s,b));
                    break;
            case 4: printf("\nEnter the second string to be compared: ");
                    getchar();
                    scanf("%[^\n]", &b);
                    strcmp(s,b);
                    break;
            case 5: printf("\nEnter the second string to be concatenated: ");
                    getchar();
                    scanf("%[^\n]", &b);
                    printf("\nMain String: %s\nSecondary String: %s", s,b);
                    printf("\nAfter concatenation: %s",strcat(s,b));
                    break;
            case 6: palindrome(s);
                    break;
            case 7: printf("\nEnter the substring to be checked for: ");
                    getchar();
                    scanf("%[^\n]", &b);
                    printf("\nMain String: %s\nSubstring: %s", s,b);
                    int c=substr(b,s);
                    if (c==-1)
                     printf("\nSubstring is not present!\n");
                    else
                     printf("\nSubstring is present at position: %d\n", c);
                    break;
            case 8: goto A;
            case 9: exit(0);
            default: printf("\nWrong choice! Enter again...\n");
                     goto B;
            
        }
    }
    return 0;
}