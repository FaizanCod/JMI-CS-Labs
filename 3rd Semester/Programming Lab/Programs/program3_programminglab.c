#include <stdio.h>
#include <stdlib.h>
char num[200];  //to store the converted hexa number

int length (char *a)
{
    int len=0;
    for (int i=0; a[i]!='\0'; i++)
     len++;
    return len;
}

void decimal_to_hex (int n)
{
    int i=0;                  
    while (n!=0)
    {
        int temp=n%16;          
        if (temp<10)                //to check for temp being a digit
        {
            num[i] = temp + 48;    //using ASCII values (base value at 48 is 0)
            i++;
        }
        else 
        {
            num[i] = temp + 55;    //55+10= 65 is the base value of A in ASCII
            i++;
        }
        n/=16;                      //dividing number each time by 16 until it becomes 0
    }
}

int hex_to_decimal (char *n)
{
    int base=1;             //16^0
    int val=0;
    for (int i=length(n); i>=0; i--)        //reading string in reverse order
    {
        if (n[i]>='0' && n[i]<='9')
        {
            val+= ((int)n[i]-48) * base;    //using ASCII values (base value at 48 is 0) 
            base*=16;
        }
        else if (n[i]>='A' && n[i] <= 'F')
        {
            val+= ((int)n[i]-55) * base;    //char-55 gives a digit since alphabets start from 65
            base*=16;
        }
    }
    return val;
}

int main()
{
    int ch,n, dec;
    char hex[200];
    printf("\nFAIZAN CHOUDHARY\n20BCS021\n");
    while (1)
    {
        A:
        printf("\n\nCONVERSION MENU\n1. Decimal to Hexadecimal\n2. Hexadecimal to Decimal\n3. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: printf("Enter the decimal number: ");
                    scanf("%d", &n);
                    decimal_to_hex(n);
                    printf("\nThe number after the conversion is: ");
                    for (int j=length(num); j>=0; j--)        //to print in reverse
                     printf("%c" , num[j]);
                    break;

            case 2: printf("Enter the hexadecimal number (in standard format): ");
                    scanf("%s", &hex);
                    dec = hex_to_decimal(hex);
                    printf("\nThe number after the conversion is: %d", dec, "\n");
                    break;

            case 3: exit(0);
            default: printf("\nWrong choice! Enter again...\n");
                     goto A;
        }
    }
    return 0;
}
