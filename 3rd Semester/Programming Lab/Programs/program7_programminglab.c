#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch = 'y';
    char text[400];
    int i=0, j, c=0;
    printf("\nFAIZAN CHOUDHARY\n20BCS021\n\n");

    do 
    {
        printf("\nEnter the piece of text (terminating with $): \n");
        scanf("%[^$]", &text);

        long no_of_spaces = 0, no_of_tabs =0, no_of_sentences = 0, no_of_vowels = 0;
        // long no_of_lines = 0;

        for (i=0; text[i]!='\0'; i++)
        {
            if (text[i]== ' ')
             no_of_spaces++;
            if (text[i]== '\t')
             no_of_tabs++;
            if (text[i]== '.' || text[i]== '!' || text[i]== '?')
             no_of_sentences++;
            // if (text[i] == '\n');
            //  no_of_lines++;
            if (text[i]=='A' || text[i]=='a' || text[i]=='E' || text[i]=='e' || text[i]=='I' || text[i]=='i' || text[i]=='O' || text[i]=='o' || text[i]=='U' || text[i]=='u')
             no_of_vowels++;
         
        }

        // to format the extra spaces to one space
        i=0, j=0;
        char second[400];
        while (text[i] != '\0') 
        {
            if (text[i]== ' ')
            {
                int temp = i+1;
                if (text[temp] != '\0') 
                {
                    while (text[temp] == ' ' && text[temp] != '\0') 
                    {
                        if (text[temp] == ' ')
                         i++;
                        temp++;
                    }  
                }
            }
            second[j] = text[i];
            i++;
            j++;
        } 
        second[j]='\0';
            
        printf("\nNumber of spaces : %d\n", no_of_spaces);
        printf("Number of tabs: %d\n", no_of_tabs);
        printf("Number of sentences: %d\n", no_of_sentences);
        // printf("Number of lines: %d\n", no_of_lines);
        printf("Number of vowels: %d\n", no_of_vowels);

        printf("\nFormatted piece of text:\n");
        for (i=0; second[i]!='\0'; i++)       
         printf("%c", second[i]);
        printf("\n");

        A:
        printf("\nDo you want to enter more? (Y/N): ");
        getchar();             
        getchar();
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}